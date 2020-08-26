#pragma once
#include "TypeDefinition.hpp"
#include "Task.hpp"

using std::vector;
using std::thread;
using std::function;

namespace Engine
{
	class ThreadPool
	{

		friend void ::JobBase(int index, ThreadPool* pool);

	private:
		size_t _thread_count;

		vector<bool> _running;

		vector<bool> _executed;

		vector<bool> _repeating;

		vector<function<void()>> _tasks;

		vector<bool> _update_task;

		vector<thread> _threads;

	public:

		ThreadPool(size_t numThreads)
		{
			for (size_t i = 0; i < numThreads; ++i)
			{
				add_thread(i);
			}
		}

		void set_task_of(size_t threadIndex, bool repeat, function<void()> task)
		{
			while (!_executed[threadIndex])
			{
				//wait
			}
			GLOBALMUTEX.lock();
			_tasks[threadIndex] = task;
			_repeating[threadIndex] = repeat;
			_executed[threadIndex] = false;
			_update_task[threadIndex] = true;
			GLOBALMUTEX.unlock();
		}

		inline bool is_executed(const size_t threadIndex)const { return _executed[threadIndex]; }

		~ThreadPool()
		{
			GLOBALMUTEX.lock();
			for (size_t i = 0; i < _thread_count; ++i)
			{
				_running[i] = false;
			}
			GLOBALMUTEX.unlock();

			for (size_t i = 0; i < _thread_count; ++i)
			{
				_threads[i].join();
			}
		}

	private:

		void add_thread(size_t index)
		{
			_tasks.emplace_back([] {});
			_running.emplace_back(true);
			_executed.emplace_back(false);
			_repeating.emplace_back(false);
			_update_task.emplace_back(false);
			_threads.emplace_back(JobBase, index, this);
		}

		inline function<void()> get_task_at(size_t index) const { return _tasks[index]; }

		inline bool is_running(const size_t index) const { return _running[index]; }

		inline bool is_repeating(const size_t index) const { return _repeating[index]; }

		inline bool is_updated(const size_t index) const { return _update_task[index]; }

		inline void toggle_update(const size_t index) { _update_task[index] = false; }

		inline void set_execute(const size_t index, bool value) { _executed[index] = value; }
	};
}