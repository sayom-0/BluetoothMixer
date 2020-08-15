#include <iostream>
#include <vector>
#include "Utils.h"
#include "UIObjs/GenericUi.h"
#include "ShellExec.h"
#include <boost/tokenizer.hpp>

int main()
{
	std::cout << "Starting BMixer..." << std::endl << "Powered by boost & bluez-tools" << std::endl
			  << "Programed by Sayom" << std::endl;

	bool playing = false;
	bool r = true;
	int screen = 0; // 0 is select, 1 is menu
	int selected = 1; //-1 will select sub audio source for device,  0 is last, 1 is play/pause, 2 is next;
	std::vector<std::string> names, macs;
	std::string elist = ShellExec::list();
	std::string cmac;
	std::string cname;
	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tokens(elist, sep);
	for (const auto &t : tokens)
	{
		std::cout << "Adding Device/Mac index : " << t << std::endl;
		names.push_back(t);
	}
	names.erase(names.begin());
	std::cout << "Cloning Names/Macs into Macs Vector and removing names..." << std::endl;
	macs = names;
	for (int i = 0; i != macs.size(); i++)
	{
		macs[i].pop_back();
		macs[i] = macs[i].substr(macs[i].find("(") + 1);
		std::cout << "Substringed " << names[i] << " into " << macs[i] << std::endl;
	}
	GenericUI MUI = GenericUI(std::stoi(Utils::exec("tput -T xterm lines")),
							  std::stoi(Utils::exec("tput -T xterm cols")));
	std::system("clear");
	std::cout << MUI.getSelect(names);
	Utils::cZero();

	char input;
	for (; r;)
	{
		input = Utils::getch2();
		if (screen == 0)
		{
			if (input == 'q')
			{
				r = false;
			} else
			{
				int i = input - '0';
				cmac = macs[i - 1];
				ShellExec::connect(macs[i - 1]);
				std::system("clear");
				cname = names[i - 1].substr(0, names[i - 1].find("(") - 1);
				std::cout << MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac));
				screen = 1;
			}
		} else if (screen == 1)
		{
			if (input == 'q')
			{
				r = false;
			} else if (input == ' ')
			{
				if (playing)
				{
					ShellExec::pause(cmac);
					playing = false;
				} else
				{
					ShellExec::play(cmac);
					playing = true;
				}
			} else if (input == 'd')
			{
				ShellExec::disconnect(cmac);
				std::system("clear");
				std::cout << MUI.getSelect(names);
				screen = 0;
			} else if (input == '\n')
			{
				if (selected == 0)
				{
					ShellExec::previous(cmac);
				} else if (selected == 1)
				{
					if (playing)
					{
						ShellExec::pause(cmac);
						playing = false;
					} else
					{
						ShellExec::play(cmac);
						playing = true;
					}
				} else if (selected == 2)
				{
					ShellExec::next(cmac);
				}
			} else if (input == (27, 91, 68))//left
			{
				selected--;
				if (selected < 0)
				{
					selected = 0;
				}
				std::system("clear");
				std::cout << MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac));
			} else if (input == (27, 91, 67))//right
			{
				selected++;
				if (selected > 2)
				{
					selected = 2;
				}
				std::system("clear");
				std::cout << MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac));
			}
		}
	}
	return 0;
}