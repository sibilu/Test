using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class countdownTimer : MonoBehaviour
{

    bool start = false;
    float currentTime = 0;
    float startingTime = 2;

    [SerializeField] Text countdownText;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
     

        if (GameObject.Find("myOVR").GetComponent<OVRhandling>().leftTrigger)
        {
           // Debug.Log("left pressed");

            start = true;
            currentTime = startingTime;
        }



        if (start == true)
        {
            currentTime -= 1 * Time.deltaTime;
            countdownText.text = currentTime.ToString("0");
            countdownText.enabled = true;
        }
        
        if (currentTime <= 0.01)
        {
            countdownText.enabled = false;
           start = false;

        }
}
}
