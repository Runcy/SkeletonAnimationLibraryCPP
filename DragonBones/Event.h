#pragma once
#include "preDB.h"
namespace dragonBones
{
	class Event
	{
		String _type;
	public:
		Event(const String &type)
		: _type(type)
		{};
		virtual ~Event(){};

		const String &getType()const
		{
			return _type;
		}
	};

	class EventDispatcher
	{
	public:
		typedef void (*Function)(Event *event , void *userData);
		// 使用 EventDispatcher 对象注册事件侦听器对象，以使侦听器能够接收事件通知。 
		void addEventListener(const String &type, Function listener , void *userData);

		// 将事件调度到事件流中。
		void dispatchEvent(Event *event);

		// 检查 EventDispatcher 对象是否为特定事件类型注册了任何侦听器。  
		bool hasEventListener(const String &type)const;

		// 从 EventDispatcher 对象中删除侦听器。 
		void removeEventListener(const String &type, Function listener);
	protected:

		typedef std::pair<Function , void*> Callback;
		typedef std::list<Callback> Listeners;
		typedef std::map<String , Listeners> EventListeners;
		// 保存所有侦听器列表
		EventListeners mEventListeners;
	};
}