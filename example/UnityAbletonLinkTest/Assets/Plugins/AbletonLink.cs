using UnityEngine;
using System;
using System.Runtime.InteropServices;

public class AbletonLink: IDisposable
{
	private static object lockOjbect = new object();
	private static volatile AbletonLink singletonInstance;
	private IntPtr nativeInstance = IntPtr.Zero;
	private const double INITIAL_TEMPO = 120.0;

	public static AbletonLink Instance
	{
		get
		{
			if (singletonInstance == null)
			{
				lock (lockOjbect)
				{
					singletonInstance = new AbletonLink();
					singletonInstance.setup(INITIAL_TEMPO);
				}
			}
			return singletonInstance;
		}
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern IntPtr CreateAbletonLink();
	private AbletonLink()
	{
		nativeInstance = CreateAbletonLink();
	}

	~AbletonLink()
	{
		this.Dispose();
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void DestroyAbletonLink(IntPtr ptr);
	public void Dispose()
	{
		if (nativeInstance != IntPtr.Zero) {
			DestroyAbletonLink(nativeInstance);
			nativeInstance = IntPtr.Zero;
		}
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void setup(IntPtr ptr, double bpm);
	private void setup(double bpm)
	{
		setup(nativeInstance, bpm);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void setTempo(IntPtr ptr, double bpm);
	public void setTempo(double bpm)
	{
		setTempo(nativeInstance, bpm);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern double tempo(IntPtr ptr);
	public double tempo()
	{
		return tempo(nativeInstance);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void setQuantum(IntPtr ptr, double quantum);
	public void setQuantum(double quantum)
	{
		setQuantum(nativeInstance, quantum);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern double quantum(IntPtr ptr);
	public double quantum()
	{
		return quantum(nativeInstance);
	}

    #if UNITY_IPHONE
    [DllImport ("__Internal")]
    #else
    [DllImport("UnityAbletonLink")]
    #endif
    private static extern void forceBeatAtTime(IntPtr ptr, double beat);
    public void forceBeatAtTime(double beat)
    {
        forceBeatAtTime(nativeInstance, beat);
    }

    #if UNITY_IPHONE
    [DllImport ("__Internal")]
    #else
    [DllImport("UnityAbletonLink")]
    #endif
    private static extern void requestBeatAtTime(IntPtr ptr, double beat);
    public void requestBeatAtTime(double beat)
    {
        requestBeatAtTime(nativeInstance, beat);
    }

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void enable(IntPtr ptr, bool bEnable);
	public void enable(bool bEnable)
	{
		enable(nativeInstance, bEnable);
	}

    #if UNITY_IPHONE
    [DllImport ("__Internal")]
    #else
    [DllImport("UnityAbletonLink")]
    #endif
    private static extern bool isEnabled(IntPtr ptr);
    public bool isEnabled()
    {
        return isEnabled(nativeInstance);
    }

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern int numPeers(IntPtr ptr);
	public int numPeers()
	{
		return numPeers(nativeInstance);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void update(IntPtr ptr, out double beat, out double phase, out double tempo, out double time, out int numPeers);
    public void update(out double beat, out double phase, out double tempo, out double time, out int numPeers)
	{
        update(nativeInstance, out beat, out phase, out tempo, out time, out numPeers);
	}

//	public delegate void NumPeersCallbackDelegate(int peers);
//#if UNITY_IPHONE
//	[DllImport ("__Internal")]
//#else
//	[DllImport("UnityAbletonLink")]
//#endif
//	private static extern void setNumPeersCallback(IntPtr ptr, IntPtr func);
//	public void setNumPeersCallback(IntPtr func)
//	{
//		setNumPeersCallback(nativeInstance, func);
//	}

//	public delegate void TempoCallbackDelegate(double bpm);
//#if UNITY_IPHONE
//	[DllImport ("__Internal")]
//#else
//	[DllImport("UnityAbletonLink")]
//#endif
//	private static extern void setTempoCallback(IntPtr ptr, IntPtr func);
//	public void setTempoCallback(IntPtr func)
//	{
//		setTempoCallback(nativeInstance, func);
//	}
}
