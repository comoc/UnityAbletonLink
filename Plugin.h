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

#ifndef Plugin_h
#define Plugin_h

#include "MyAbletonLink.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY) || defined(__CYGWIN32__)
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)
#else
#define UNITY_INTERFACE_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif
    void* UNITY_INTERFACE_EXPORT CreateAbletonLink();
    void UNITY_INTERFACE_EXPORT DestroyAbletonLink(void* ptr);
    
    void UNITY_INTERFACE_EXPORT setup(void* ptr, double bpm);
    
    void UNITY_INTERFACE_EXPORT setTempo(void* ptr, double bpm);
    double UNITY_INTERFACE_EXPORT tempo(void* ptr);
    
    void UNITY_INTERFACE_EXPORT setQuantum(void* ptr, double quantum);
    double UNITY_INTERFACE_EXPORT quantum(void* ptr);
    
    bool UNITY_INTERFACE_EXPORT isEnabled(void* ptr);
    void UNITY_INTERFACE_EXPORT enable(void* ptr, bool bEnable);
    
    int UNITY_INTERFACE_EXPORT numPeers(void* ptr);
    void UNITY_INTERFACE_EXPORT update(void* ptr, double* rbeat, double* rphase);
#ifdef __cplusplus
}
#endif

#endif /* Plugin_h */
