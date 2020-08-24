#include <iostream>
#include <vector>
#include "Utils.h"
#include "UIObjs/GenericUi.h"
#include "ShellExec.h"
#include <boost/tokenizer.hpp>
#include <thread>

[[noreturn]] void Monitor(GenericUI &gui, std::string &cname, int &selected, std::string &cmac, int &screen)
{
	int rows, cols;
	for (;;)
	{
		sleep(1);
		if (screen == 1)
		{
			rows = std::stoi(Utils::exec("tput -T xterm lines"));
			cols = std::stoi(Utils::exec("tput -T xterm cols"));
			std::system("clear");
			gui.setCols(cols);
			gui.setRows(rows);
			if (ShellExec::getVol(ShellExec::getpactlID(cmac)) > 1.1)
			{
				std::string cmd = "pactl set-source-volume " + std::to_string(ShellExec::getpactlID(cmac)) + " 1.32";
				std::system(cmd.c_str());
			}
			if (ShellExec::getVol(ShellExec::getpactlID(cmac)) < 0.2)
			{
				std::string cmd = "pactl set-source-volume " + std::to_string(ShellExec::getpactlID(cmac)) + " 0.008";
				std::system(cmd.c_str());
			}
			std::cout
					<< gui.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
								   ShellExec::getTotalTime(cmac),
								   ShellExec::getCurrentTime(cmac),
								   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
								   ShellExec::getVol(ShellExec::getpactlID(cmac)));

		}
	}
}

int main()
{
	std::cout << "Starting BMixer..." << std::endl;

	std::cout << "Creating base Objects" << std::endl;

	bool r = true;
	int screen = 0; // 0 is select, 1 is menu
	int selected = 1; //-1 will select sub audio source for device,  0 is last, 1 is play/pause, 2 is next;
	std::vector<std::string> names, macs;
	std::string cmac;
	std::string cname;

	std::cout << "	Done" << std::endl;

	std::cout << "Loading bluetooth addresses" << std::endl;

	std::string elist = ShellExec::list();
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

	std::cout << "	Done" << std::endl;

	std::cout << "Creating GenericUI" << std::endl;

	GenericUI MUI = GenericUI(std::stoi(Utils::exec("tput -T xterm lines")),
							  std::stoi(Utils::exec("tput -T xterm cols")));
	std::cout << "	Done" << std::endl;


	std::cout << "Starting adaption thread" << std::endl;

	std::thread t(std::ref(Monitor), std::ref(MUI), std::ref(cname), std::ref(selected), std::ref(cmac),
				  std::ref(screen));
	t.detach();

	std::cout << "	Done" << std::endl;

	std::system("clear");
	std::cout << MUI.getSelect(names);

	int input;
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
				std::cout << "Connecting..." << std::endl;
				int i = input - '0';
				cmac = macs[i - 1];
				ShellExec::connect(macs[i - 1]);
				sleep(3);
				std::system("clear");
				cname = names[i - 1].substr(0, names[i - 1].find("(") - 1);
				std::cout
						<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
									   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
									   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
									   ShellExec::getVol(ShellExec::getpactlID(cmac)));
				screen = 1;
			}
		} else if (screen == 1)
		{
			if (input == 'q')
			{
				r = false;
			} else if (input == ' ')
			{
				if (ShellExec::getStatus(cmac))
				{
					ShellExec::pause(cmac);
					std::cout << MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
											 ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
											 ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
											 ShellExec::getVol(ShellExec::getpactlID(cmac)));
				} else
				{
					ShellExec::play(cmac);
					std::cout << MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
											 ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
											 ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
											 ShellExec::getVol(ShellExec::getpactlID(cmac)));
				}
			} else if (input == 'd')
			{
				std::cout << "Disconnecting..." << std::endl;
				screen = 0;
				ShellExec::disconnect(cmac);
				sleep(3);
				std::system("clear");
				std::cout << MUI.getSelect(names);
			} else if (input == '\n')
			{
				if (selected == 0)
				{
					ShellExec::previous(cmac);
				} else if (selected == 1)
				{
					if (ShellExec::getStatus(cmac))
					{
						ShellExec::pause(cmac);
						std::cout
								<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
											   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
											   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
											   ShellExec::getVol(ShellExec::getpactlID(cmac)));
					} else
					{
						ShellExec::play(cmac);
						std::cout
								<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
											   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
											   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
											   ShellExec::getVol(ShellExec::getpactlID(cmac)));
					}
				} else if (selected == 2)
				{
					ShellExec::next(cmac);
				}
			} else if (input == (27, 91, 68))//left
			{
				selected--;
				if (selected < -1)
				{
					selected = -1;
				}
				std::system("clear");
				std::cout
						<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
									   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
									   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
									   ShellExec::getVol(ShellExec::getpactlID(cmac)));
			} else if (input == (27, 91, 67))//right
			{
				selected++;
				if (selected > 2)
				{
					selected = 2;
				}
				std::system("clear");
				std::cout
						<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
									   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
									   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
									   ShellExec::getVol(ShellExec::getpactlID(cmac)));
			} else if (selected == -1 && input == (27, 91, 65))
			{
				ShellExec::volUp(ShellExec::getpactlID(cmac));
				std::system("clear");
				std::cout
						<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
									   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
									   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
									   ShellExec::getVol(ShellExec::getpactlID(cmac)));
			} else if (selected == -1 && input == (27, 91, 66))
			{
				ShellExec::volDown(ShellExec::getpactlID(cmac));
				std::system("clear");
				std::cout
						<< MUI.getMenu(cname, selected, ShellExec::trackInfo(cmac), ShellExec::getStatus(cmac),
									   ShellExec::getTotalTime(cmac), ShellExec::getCurrentTime(cmac),
									   ShellExec::getRawCurrentTime(cmac) / ShellExec::getRawTotalTime(cmac),
									   ShellExec::getVol(ShellExec::getpactlID(cmac)));
			}
		}
	}
	return 0;
}