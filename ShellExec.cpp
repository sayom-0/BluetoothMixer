//
// Created by sjet on 8/13/20.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/token_functions.hpp>
#include <boost/tokenizer.hpp>
#include "ShellExec.h"
#include "Utils.h"

void ShellExec::pause(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string cmd = "dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
					  "/player0 org.bluez.MediaPlayer1.Pause > /dev/null";
	std::system(cmd.c_str());
}

void ShellExec::play(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string cmd = "dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
					  "/player0 org.bluez.MediaPlayer1.Play > /dev/null";
	std::system(cmd.c_str());
}

std::string ShellExec::list()
{
	return Utils::exec("bt-device -l");
}

void ShellExec::connect(std::string target)
{
	std::string cmd = "bluetoothctl -- connect " + target + " > /dev/null";
	std::system(cmd.c_str());
}

void ShellExec::disconnect(std::string target)
{
	std::string cmd = "bluetoothctl -- disconnect " + target + " > /dev/null";
	std::system(cmd.c_str());
}

void ShellExec::next(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string cmd = "dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
					  "/player0 org.bluez.MediaPlayer1.Next > /dev/null";
	std::system(cmd.c_str());
}

void ShellExec::previous(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string cmd = "dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
					  "/player0 org.bluez.MediaPlayer1.Previous > /dev/null";
	std::system(cmd.c_str());
}

std::string ShellExec::trackInfo(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string sr = Utils::exec(
			"qdbus --system org.bluez /org/bluez/hci0/dev_" + macadr + "/player0 org.bluez.MediaPlayer1.Track");
	std::vector<std::string> srvec;

	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tokens(sr, sep);
	for (const auto &t : tokens)
	{
		srvec.push_back(t);
	}
	std::string info = srvec[1].substr(8) + " - " +
					   srvec[0].substr(7) + " - " +
					   srvec[5].substr(7);
	return info;
}

std::string ShellExec::getTotalTime(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string sr = Utils::exec(
			"qdbus --system org.bluez /org/bluez/hci0/dev_" + macadr + "/player0 org.bluez.MediaPlayer1.Track");
	std::vector<std::string> srvec;
	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tokens(sr, sep);
	for (const auto &t : tokens)
	{
		srvec.push_back(t);
	}
	int rtime = std::stoi(srvec[2].substr(9));
	rtime /= 1000;
	std::string info;
	if (int((rtime % 60) / 10) > 0)
	{
		info = std::to_string(rtime / 60) + ":" + std::to_string(rtime % 60);
	} else
	{
		info = std::to_string(rtime / 60) + ":0" + std::to_string(rtime % 60);
	}
	return info;
}

std::string ShellExec::getCurrentTime(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	int rtime = std::stoi(Utils::exec(
			"qdbus --system org.bluez /org/bluez/hci0/dev_" + macadr + "/player0 org.bluez.MediaPlayer1.Position"));
	rtime /= 1000;
	std::string info;
	if (int((rtime % 60) / 10) > 0)
	{
		info = std::to_string(rtime / 60) + ":" + std::to_string(rtime % 60);
	} else
	{
		info = std::to_string(rtime / 60) + ":0" + std::to_string(rtime % 60);
	}

	return info;
}

bool ShellExec::getStatus(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	if (Utils::exec(
			"qdbus --system org.bluez /org/bluez/hci0/dev_" + macadr + "/player0 org.bluez.MediaPlayer1.Status") ==
		"playing\n")
	{
		return true;
	} else
	{
		return false;
	}
}

double ShellExec::getRawTotalTime(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string sr = Utils::exec(
			"qdbus --system org.bluez /org/bluez/hci0/dev_" + macadr + "/player0 org.bluez.MediaPlayer1.Track");
	std::vector<std::string> srvec;
	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tokens(sr, sep);
	for (const auto &t : tokens)
	{
		srvec.push_back(t);
	}
	int rtime = std::stoi(srvec[2].substr(9));
	rtime /= 1000;
	return rtime;
}

double ShellExec::getRawCurrentTime(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	int rtime = std::stoi(Utils::exec(
			"qdbus --system org.bluez /org/bluez/hci0/dev_" + macadr + "/player0 org.bluez.MediaPlayer1.Position"));
	rtime /= 1000;
	return rtime;
}

int ShellExec::getpactlID(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	std::string input = Utils::exec("pactl list sources short");
	std::vector<std::string> srvec;
	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tokens(input, sep);
	for (const auto &t : tokens)
	{
		srvec.push_back(t);
	}
	for (int i = 0; i != srvec.size(); i++)
	{
		if (srvec[i].find("bluez_source." + macadr + ".a2dp_source") != -1)
		{
			return srvec[i].at(0) - '0';
		}
	}
}

void ShellExec::volUp(int ID)
{
	std::string cmd = "sh -c \"pactl set-source-volume " + std::to_string(ID) + " +5%\"";
	std::system(cmd.c_str());
}

void ShellExec::volDown(int ID)
{
	std::string cmd = "sh -c \"pactl set-source-volume " + std::to_string(ID) + " -5%\"";
	std::system(cmd.c_str());
}

double ShellExec::getVol(int ID)
{
	std::string input = Utils::exec("pactl list sources");
	std::string search = "Source #" + std::to_string(ID);
	bool occ = false;
	std::vector<std::string> srvec;
	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tokens(input, sep);
	for (const auto &t : tokens)
	{
		srvec.push_back(t);
	}
	for (int i = 0; i != srvec.size(); i++)
	{
		if (srvec[i].find(search) != -1)
		{
			if (!occ)
			{
				for (int j = 0; j != i; j++)
				{
					srvec.erase(srvec.begin());
				}
				search = "Volume:";
				i = 0;
				occ = true;
			} else
			{
				return std::stoi(srvec[i].substr(srvec[i].find('/') + 2, 3)) * 0.01;
			}
		}
	}
}