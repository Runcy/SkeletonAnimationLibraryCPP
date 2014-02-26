#pragma once
#include "preDB.h"
#include "Event.h"
namespace dragonBones
{
	//[Event(name="sound",type="dragonBones.events.SoundEvent")]
	
	/**
	 * @private
	 */
	class SoundEventManager : public EventDispatcher
	{
	private :
		static SoundEventManager *_instance;
		
	public :
		static SoundEventManager* getInstance()
		{
			if (!_instance)
			{
				_instance = new SoundEventManager();
			}
			return _instance;
		}
		
		SoundEventManager()
		{
			if (_instance)
			{
				throw std::exception("Singleton already constructed!");
			}
		}
	};
}