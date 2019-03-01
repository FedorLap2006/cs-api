#pragma once

#ifdef WIN32

#pragma comment(lib,"winmm.lib")

#include <windows.h>

#else

#include <alsa/asoundlib.h>

#endif

#include <vector>
#include <iterator>

namespace sapi{
	typedef double snode;
	
#ifdef WIN32
	int getOutNumDevs() { return waveOutGetNumDevs(); }
#else
	// ...
#endif
//	void PlaySound(vector<spectre> sp,size_t dur); // milliseconds
//	void PlaySound(spectre sp,size_t dur); // milliseconds
	
	class Audio {
		public:
			Audio(size_t did) : devid(did){}
			~Audio() = default;
			
			void setBuffer(std::vector<snode> buf);
			std::vector<snode> getBuffer(void) { return buf; }
			virtual bool run() = 0;


		protected:
			std::vector<snode> buf;
			size_t devid;
	};

	class Record : public Audio {
		public:

	};
	class Sound : public Audio {
		public:
			bool run() override;
	};

}


