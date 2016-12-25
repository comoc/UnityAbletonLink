using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent (typeof (Text))]
public class LinkInfo : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		double tempo = AbletonLink.Instance.tempo ();
		double quantum = AbletonLink.Instance.quantum ();
		double beat, phase;
		AbletonLink.Instance.update (out beat, out phase);
		GetComponent<Text> ().text = "Tempo:" + tempo + " Quantum:" + quantum + "\n"
			+ " Beat:" + beat + " Phase:" + phase;
	}
}
