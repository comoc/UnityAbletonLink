using UnityEngine;
using System;
using System.Runtime.InteropServices;

public class AbletonLink: IDisposable
{
	private static AbletonLink singletonInstance;
	private IntPtr instance = IntPtr.Zero;

	public static AbletonLink Instance
	{
		get
		{
			if (singletonInstance == null)
				singletonInstance = new AbletonLink();
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
		instance = CreateAbletonLink();
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
		if (instance != IntPtr.Zero) {
			DestroyAbletonLink(instance);
			instance = IntPtr.Zero;
		}
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void setup(IntPtr ptr, double bpm);
	public void setup(double bpm)
	{
		setup(instance, bpm);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void setTempo(IntPtr ptr, double bpm);
	public void setTempo(double bpm)
	{
		setTempo(instance, bpm);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern double tempo(IntPtr ptr);
	public double tempo()
	{
		return tempo(instance);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void setQuantum(IntPtr ptr, double quantum);
	public void setQuantum(double quantum)
	{
		setQuantum(instance, quantum);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern double quantum(IntPtr ptr);
	public double quantum()
	{
		return quantum(instance);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern bool isEnabled(IntPtr ptr);
	public bool isEnabled()
	{
		return isEnabled(instance);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void enable(IntPtr ptr, bool bEnable);
	public void enable(bool bEnable)
	{
		enable(instance, bEnable);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern int numPeers(IntPtr ptr);
	public int numPeers()
	{
		return numPeers(instance);
	}

	#if UNITY_IPHONE
	[DllImport ("__Internal")]
	#else
	[DllImport ("UnityAbletonLink")]
	#endif
	private static extern void update(IntPtr ptr, out double beat, out double phase);
	public void update(out double beat, out double phase)
	{
		update(instance, out beat, out phase);
	}
}
