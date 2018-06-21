/* Copyright 2016, Akihiro Komori. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Plugin.h"

#ifdef __cplusplus
extern "C" {
#endif
    UNITY_INTERFACE_EXPORT void* UNITY_INTERFACE_API CreateAbletonLink()
    {
        return new MyAbletonLink();
    }
    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API DestroyAbletonLink(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        delete link;
    }
    
    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setup(void* ptr, double bpm)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->setup(bpm);
    }
    
    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempo(void* ptr, double bpm)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->setTempo(bpm);
    }
    
    UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API tempo(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return link->tempo();
    }
    
    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setQuantum(void* ptr, double quantum)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->setQuantum(quantum);
    }

    UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API quantum(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return link->quantum();
    }

    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API forceBeatAtTime(void* ptr, double beat)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->forceBeatAtTime(beat);
    }
    
    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API requestBeatAtTime(void* ptr, double beat)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->requestBeatAtTime(beat);
    }
    
    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API enable(void* ptr, bool bEnable)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->enable(bEnable);
    }

    UNITY_INTERFACE_EXPORT bool UNITY_INTERFACE_API isEnabled(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return link->isEnabled();
    }
    
    UNITY_INTERFACE_EXPORT int UNITY_INTERFACE_API numPeers(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return static_cast<int>(link->numPeers());
    }

    UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API update(void* ptr, double* rbeat, double* rphase, double* rtempo, double* rtime, int* rnumPeers)
    {
//        double tempo;
//        double quantam;
//        double time;
//        int numPeers;
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        MyAbletonLink::Status s = link->update();
        *rbeat = s.beat;
        *rphase = s.phase;
        *rtempo = s.tempo;
        *rtime = s.time;
        *rnumPeers = s.numPeers;
    }

	//UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setNumPeersCallback(void* ptr, numPeersCallback func)
	//{
 //       MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
	//	link->setNumPeersCallback(func);
	//}
	//
	//UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempoCallback(void* ptr, tempoCallback func)
	//{
 //       MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
	//	link->setTempoCallback(func);

	//}

#ifdef __cplusplus
}
#endif
