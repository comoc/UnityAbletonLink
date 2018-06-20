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

#ifdef __cplusplus
extern "C" {
#endif

	UNITY_INTERFACE_EXPORT void* UNITY_INTERFACE_API CreateAbletonLink();
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API DestroyAbletonLink(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setup(void* ptr, double bpm);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempo(void* ptr, double bpm);
	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API tempo(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setQuantum(void* ptr, double quantum);
	UNITY_INTERFACE_EXPORT double UNITY_INTERFACE_API quantum(void* ptr);
	UNITY_INTERFACE_EXPORT bool UNITY_INTERFACE_API isEnabled(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API enable(void* ptr, bool bEnable);
	UNITY_INTERFACE_EXPORT int UNITY_INTERFACE_API numPeers(void* ptr);
	UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API update(void* ptr, double* rbeat, double* rphase);
	//UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setNumPeersCallback(void* ptr, numPeersCallback func);
	//UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setTempoCallback(void* ptr, tempoCallback func);

#ifdef __cplusplus
}
#endif

#endif /* Plugin_h */
