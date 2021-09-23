using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OVRhandling : MonoBehaviour
{

    public bool leftTrigger;
    public bool rightTrigger;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

        OVRInput.Update();

        leftTrigger = OVRInput.Get(OVRInput.RawButton.LIndexTrigger);

        rightTrigger = OVRInput.Get(OVRInput.RawButton.RIndexTrigger);


       // Debug.Log(leftTrigger);
    }
}
