//
// Created by sjet on 8/13/20.
//

#ifndef BLUETOOTHMIXER_SHELLEXEC_H
#define BLUETOOTHMIXER_SHELLEXEC_H


#include <string>

class ShellExec
{
public:
	static void play(std::string);

	static void pause(std::string);

	static std::string list();

	static void disconnect(std::string target);

	static void connect(std::string target);

	static void previous(std::string macadr);

	static void next(std::string macadr);

	static std::string trackInfo(std::string macadr);

	static std::string getTotalTime(std::string macadr);

	static bool getStatus(std::string macadr);

	static std::string getCurrentTime(std::string macadr);

	static double getRawTotalTime(std::string macadr);

	static double getRawCurrentTime(std::string macadr);
};


#endif //BLUETOOTHMIXER_SHELLEXEC_H
