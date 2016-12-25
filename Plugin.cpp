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
    void* UNITY_INTERFACE_EXPORT CreateAbletonLink()
    {
        return new MyAbletonLink();
    }
    void UNITY_INTERFACE_EXPORT DestroyAbletonLink(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        delete link;
    }
    
    void UNITY_INTERFACE_EXPORT setup(void* ptr, double bpm)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->setup(bpm);
    }
    
    void UNITY_INTERFACE_EXPORT setTempo(void* ptr, double bpm)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->setTempo(bpm);
    }
    
    double UNITY_INTERFACE_EXPORT tempo(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return link->tempo();
    }
    
    void UNITY_INTERFACE_EXPORT setQuantum(void* ptr, double quantum)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->setQuantum(quantum);
    }

    double UNITY_INTERFACE_EXPORT quantum(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return link->quantum();
    }
    
    bool UNITY_INTERFACE_EXPORT isEnabled(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return link->isEnabled();
    }

    void UNITY_INTERFACE_EXPORT enable(void* ptr, bool bEnable)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        link->enable(bEnable);
    }
    
    int UNITY_INTERFACE_EXPORT numPeers(void* ptr)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        return static_cast<int>(link->numPeers());
    }

    void UNITY_INTERFACE_EXPORT update(void* ptr, double* rbeat, double* rphase)
    {
        MyAbletonLink* link = static_cast<MyAbletonLink*>(ptr);
        MyAbletonLink::Status s = link->update();
        *rbeat = s.beat;
        *rphase = s.phase;
    }

#ifdef __cplusplus
}
#endif
