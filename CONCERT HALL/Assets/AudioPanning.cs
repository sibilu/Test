using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class AudioPanning : MonoBehaviour
{
    float timer = 0.0f;
    public bool start = false;
    public bool switchSchene;
    public float tempTime;
    public bool switchBool = true;
    public bool leftPressed;

    
    // Start is called before the first frame update
    void Start()
    {


        
    }

    // Update is called once per frame
    void Update()
    {

        if (GameObject.Find("myOVR").GetComponent<OVRhandling>().leftTrigger)
        {
           start = true;
            leftPressed = true;
        }

        if (start == true)
        {
            timer += Time.deltaTime;
        }

        if(timer > 1)
        {
            GameObject.Find("myOVR").GetComponent<OVRhandling>().leftTrigger = false;
        }


        if (GameObject.Find("myOVR").GetComponent<OVRhandling>().rightTrigger && leftPressed)
        {
            // Debug.Log(timer-2.0f);
            tempTime = timer - 2.0f;
            switchSchene = true;
            switchBool = false;
            timer = 0;
            start = false;
            leftPressed = false;
        }

        if(GameObject.Find("myOVR").GetComponent<OVRhandling>().rightTrigger == false)
        {
            switchBool = true;
        }

        
        //
    }


}
