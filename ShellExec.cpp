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