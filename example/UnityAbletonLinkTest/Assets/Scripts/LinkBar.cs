using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LinkBar : MonoBehaviour {

	float prev = 1.0f;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        double beat, phase, tempo, time;
        int numPeers;
        AbletonLink.Instance.update (out beat, out phase, out tempo, out time, out numPeers);
		double q = AbletonLink.Instance.quantum();
		//Debug.Log ("" + (phase / q));
		float p = (float)(phase / q);
		if (p < prev)
			transform.Rotate (0, 0, 15.0f);
		prev = p;
	}
}
