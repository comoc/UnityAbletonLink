# UnityAbletonLink

UnityAbletonLink is an [Ableton Link](https://github.com/Ableton/link) plugin for [Unity](https://unity3d.com).

## Building

After checked out the UnityAbletonLink repository, then check out all dependencies.

```
cd UnityAbletonLink
git submodule update --init --recursive
```

Open `UnityAbletonLink.xcodeproj` with Xcode, then build it.

## Running

Create a new Unity project.
Create a `Plugins` folder under the `Assets` folder of the project.

### Mac

Copy `UnityAbletonLink.bundle` and `CSharp/AbletonLink.cs` into the `Plugins` folder.

### Windows

Copy `CSharp/AbletonLink.cs` into the `Plugins` folder.
Create the `x86_64` folder under the `Plugins` folder.
Copy `UnityAbletonLink.dll` into the `Plugins/x86_64` folder.

Where `AbletonLink.cs` is a wrapper script for `UnityAbletonLink` plugin.

Write some script to use it.
For example,

```Example.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Example : MonoBehaviour {

	private AbletonLink link;

	// Use this for initialization
	void Start () {
	}

	// Update is called once per frame
	void Update () {
        	double beat, phase, tempo, time;
		int numPeers;
        	AbletonLink.Instance.update(out beat, out phase, out tempo, out time, out numPeers);

		// We can obtain the latest beat and phase like this.
		Debug.Log ("beat: " + beat + " phase:" + phase);
	}
}
```

Attach the script to a GameObject (e.g. Main Camera or something).

Play the scene and play the other Ableton Link supported application such as Ableton Live, then you can see log messages like the following.
```
...
beat: 43.151854 phase:3.151854
UnityEngine.Debug:Log(Object)
beat: 43.265132 phase:3.265132
UnityEngine.Debug:Log(Object)
...
```

## License

These codes are licensed under CC0.

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed)
