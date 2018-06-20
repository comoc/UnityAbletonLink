using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent (typeof (Text))]
public class LinkInfo : MonoBehaviour {

	// Use this for initialization
	void Start () {
		//var numPeersPtr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(new AbletonLink.NumPeersCallbackDelegate(numPeers));
		//AbletonLink.Instance.setNumPeersCallback(numPeersPtr);
		//var tempoPtr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(new AbletonLink.TempoCallbackDelegate(tempo));
		//AbletonLink.Instance.setTempoCallback(tempoPtr);
	}
	
	// Update is called once per frame
	void Update () {
		double tempo = AbletonLink.Instance.tempo ();
		double quantum = AbletonLink.Instance.quantum ();
		double beat, phase;
		AbletonLink.Instance.update (out beat, out phase);
		int numPeers = AbletonLink.Instance.numPeers();
		GetComponent<Text> ().text = "Tempo:" + tempo + " Quantum:" + quantum + "\n"
			+ "Beat:" + beat + " Phase:" + phase + "\n"
			+ "NumPeers:" + numPeers;
	}

	//AbletonLink.NumPeersCallbackDelegate numPeers = peers => {
	//	Debug.Log(System.Reflection.MethodBase.GetCurrentMethod().Name + " : " + peers);
	//};

	//AbletonLink.TempoCallbackDelegate tempo = bpm => {
	//	Debug.Log(System.Reflection.MethodBase.GetCurrentMethod().Name + " : " + bpm);
	//};

}
