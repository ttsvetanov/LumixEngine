#pragma once
#include "core/lux.h"

namespace Lux
{
	namespace MT
	{
		typedef void* MutexHandle;

		class LUX_CORE_API Mutex
		{
		public:
			explicit Mutex(bool locked);
			~Mutex();

			void lock();
			bool poll();

			void unlock();

		private:
			MutexHandle m_id;
		};

		class Lock
		{
		public:
			Lock(Mutex& mutex) : m_mutex(mutex) { mutex.lock(); }
			~Lock() { m_mutex.unlock(); }

		private:
			void operator=(const Lock&);
			Mutex& m_mutex;
		};
	} // ~namespace MT
}; // ~namespace Lux