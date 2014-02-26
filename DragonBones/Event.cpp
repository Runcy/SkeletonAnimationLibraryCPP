#include "Event.h"
namespace dragonBones
{

	// 使用 EventDispatcher 对象注册事件侦听器对象，以使侦听器能够接收事件通知。 
	void EventDispatcher::addEventListener(const String &type, Function listener , void *userData)
	{
		Listeners &list = mEventListeners[type];
		list.push_back(Callback(listener ,userData));
	}

	// 将事件调度到事件流中。
	void EventDispatcher::dispatchEvent(Event *event)
	{
		EventListeners::iterator iter = mEventListeners.find(event->getType());
		if(iter != mEventListeners.end())
		{
			for(Listeners::iterator iterCallback = iter->second.begin() ; iterCallback != iter->second.end() ; iterCallback ++)
			{
				iterCallback->first(event , iterCallback->second);
			}
		}
		delete event;
	}

	// 检查 EventDispatcher 对象是否为特定事件类型注册了任何侦听器。  
	bool EventDispatcher::hasEventListener(const String &type)const
	{
		return mEventListeners.find(type) != mEventListeners.end();
	}

	// 从 EventDispatcher 对象中删除侦听器。 
	void EventDispatcher::removeEventListener(const String &type, Function listener)
	{
		EventListeners::iterator iter = mEventListeners.find(type);
		if(iter != mEventListeners.end())
		{
			for(Listeners::iterator iterCallback = iter->second.begin() ; iterCallback != iter->second.end() ; )
			{
				if(iterCallback->first == listener)
				{
					iterCallback = iter->second.erase(iterCallback);
				}
				else
				{
					iterCallback ++;
				}
			}
		}
	}


}