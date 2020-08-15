//
// Created by sjet on 8/13/20.
//

#include <zconf.h>
#include <algorithm>
#include "ShellExec.h"
#include "Utils.h"

void ShellExec::pause(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	Utils::exec("dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
				"/player0 org.bluez.MediaPlayer1.Pause");
}

void ShellExec::play(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	Utils::exec("dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
				"/player0 org.bluez.MediaPlayer1.Play");
}

std::string ShellExec::list()
{
	return Utils::exec("bt-device -l");
}

void ShellExec::connect(std::string target)
{
	std::string cmd = "bluetoothctl -- connect " + target;
	Utils::exec(cmd);
}

void ShellExec::disconnect(std::string target)
{
	std::string cmd = "bluetoothctl -- disconnect " + target;
	Utils::exec(cmd);
}

void ShellExec::next(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	Utils::exec("dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
				"/player0 org.bluez.MediaPlayer1.Next");
}

void ShellExec::previous(std::string macadr)
{
	std::replace(macadr.begin(), macadr.end(), ':', '_');
	Utils::exec("dbus-send --system --type=method_call --dest=org.bluez /org/bluez/hci0/dev_" + macadr +
				"/player0 org.bluez.MediaPlayer1.Previous");
}