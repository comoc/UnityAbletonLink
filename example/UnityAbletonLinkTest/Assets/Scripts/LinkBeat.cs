using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LinkBeat : MonoBehaviour {

	private AbletonLink link;

	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
		double beat, phase;
		AbletonLink.Instance.update (out beat, out phase);
//		Debug.Log ("beat: " + beat + " phase:" + phase);
		float fphase = (float)phase;
		fphase = fphase - Mathf.Floor (fphase);
		transform.localScale = new Vector3 (fphase, fphase, fphase);
	}
}
