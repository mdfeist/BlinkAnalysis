#include "stdafx.h"

#include "StreamHandler.h"
#include "StreamTaskQueue.h"
namespace BlinkAnalysis
{
	StreamTaskQueue::StreamTaskQueue() {
		_syncObj = gcnew Object();
		_tasks = gcnew Generic::Queue<QTask^>();
		_runningTaskCount = 0;
	}

	void StreamTaskQueue::ProcessTaskQueue(StreamTaskQueue^ queue)
	{
		if (queue->_runningTaskCount != 0) return;

		if (queue->_tasks->Count > 0 && queue->_runningTaskCount == 0)
		{
			Monitor::Enter(queue->_syncObj);
			QueueUserWorkItem(queue->_tasks->Dequeue());
			Monitor::Exit(queue->_syncObj);
		}
	}

	void StreamTaskQueue::QueueUserWorkItem(QTask^ task)
	{
		task->queue->_runningTaskCount++;

		ThreadPool::QueueUserWorkItem(gcnew WaitCallback(StreamTaskQueue::completionTask), task);
	}

	void StreamTaskQueue::OnTaskCompleted(StreamTaskQueue^ queue)
	{
		Monitor::Enter(queue->_syncObj);
		queue->_runningTaskCount--;
		if (queue->_runningTaskCount == 0)
		{
			ProcessTaskQueue(queue);
		}
		Monitor::Exit(queue->_syncObj);
	}

	void StreamTaskQueue::completionTask(Object^ task)
	{
		StreamHandler::addFrameAsync(((QTask^)task)->frame);
		OnTaskCompleted(((QTask^)task)->queue);
	}


	void StreamTaskQueue::Queue(Object^ frame)
	{
		Monitor::Enter(_syncObj);
		QTask^ task = gcnew QTask();
		task->queue = this;
		task->frame = frame;
		_tasks->Enqueue(task);
		Monitor::Exit(_syncObj);

		ProcessTaskQueue(this);
	}

	int StreamTaskQueue::Count()
	{
		Monitor::Enter(_syncObj);
		int ret = _tasks->Count;
		Monitor::Exit(_syncObj);
		return ret;
	}
}