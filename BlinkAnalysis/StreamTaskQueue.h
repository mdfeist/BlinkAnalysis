#pragma once


namespace BlinkAnalysis
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Collections;
	using namespace System::Threading;

	public ref class StreamTaskQueue
	{
	private:
		ref class QTask
		{
		public:
			//property Action<Object^>^ Task;
			property StreamTaskQueue^ queue;
			property Object^ frame;
		};

		Object^ _syncObj;
		Generic::Queue<QTask^>^ _tasks;
		int _runningTaskCount;
		bool _process;

		static void ProcessTaskQueue(StreamTaskQueue^ queue);

		static void QueueUserWorkItem(QTask^ task);

		static void OnTaskCompleted(StreamTaskQueue^ queue);

		static void completionTaskAsync(Object^ task);
	

	public:

		StreamTaskQueue();

		void Queue(Object^ frame);

		int Count();

		void setProcess(bool process)
		{
			_process = process;
		}
	};
}
