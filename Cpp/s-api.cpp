#include "s-api.h"

namespace sapi {
	void Audio::setBuffer(std::vector<snode> buf) {}
	

#ifdef WIN32
	bool Sound::run() {
		LPSTR buf;
		DWORD bsize;
		
		

	}

#else
	bool Sound::run() {

	}
#endif
}
