using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using System.IO;

public class sceneShuffler : MonoBehaviour
{

    public GameObject[] myObject;
    public int index;
    public int sceneCounter = 0;
    //public int startSceneIndex = 0;
    private int[] scenes = new int[12];
    int noOfScenes = 25;

    //public bool startScenes;

    private bool triggerActive = false;

    private int currentSceneIndex;

    private System.Random _random = new System.Random();
    private float timeToWrite;

    private bool endSceneReached = false;

    string path = "Assets/participant.txt";
    StreamWriter sr;

    // Start is called before the first frame update
    void Start()
    {
        index = 0;  
        int j = 0;
        sr = new StreamWriter(path, true);
        for (int i = 0; i < 24; i++) {
            if(i == 0)  {
                scenes[j] = i;
                j++;
            }
            
            if(i > 0)  {
                if (i % 2 == 0) { 
                    scenes[j] = i;
                    j++;
                }

            }

        }


        Shuffle(scenes);

       // startScenes = true;
        myObject = GameObject.FindGameObjectsWithTag("sceneShuffling");
        DontDestroyOnLoad(this.gameObject);
        
    }

    // Update is called once per frame
    void Update() {


        if (GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchSchene == true && GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchBool == true) {
            Debug.Log("sceneCounter: " + sceneCounter);
            Debug.Log("long fucker statement is triggered");



            if (GameObject.Find("Pan Unit").GetComponent<AudioPanning>().tempTime != -2.0f) {
                    timeToWrite = GameObject.Find("Pan Unit").GetComponent<AudioPanning>().tempTime;
                    sr.WriteLine("Scene: " + SceneManager.GetActiveScene().name + " time: " + timeToWrite);
                    Debug.Log("Scene: " + SceneManager.GetActiveScene().name + " time: " + timeToWrite);
                }
            else { }


            if (sceneCounter % 2 == 0)
            {
                Debug.Log("Block 1: " + scenes[index]);
                loadNextScene(scenes[index]);
                index++;
                sceneCounter++;
            }
            else if (sceneCounter % 2 == 1)
            {
                int param = SceneManager.GetActiveScene().buildIndex + 1;
                Debug.Log("Block 2: " + param);
                loadNextScene(param);
                sceneCounter++;
            }
           
            
            /*
         if (sceneCounter == 0)
         {
             Debug.Log("Block 1: " + scenes[index]);
             loadNextScene(scenes[index]);
             index++;
             sceneCounter++;
         } else if (sceneCounter == 1)
         {
             int param = SceneManager.GetActiveScene().buildIndex + 1;
             Debug.Log("Block 2: " + param);
             loadNextScene(param);
             sceneCounter++;
         } else if(sceneCounter % 2 == 1 && sceneCounter != 0)
         {
             int param = SceneManager.GetActiveScene().buildIndex + 1;
             Debug.Log("Block 3: " + param);
             loadNextScene(param);
             sceneCounter++;
         }
         else
         {
             Debug.Log("Block 4: " + scenes[index]);
             loadNextScene(scenes[index]);
             index++;
             sceneCounter++;
         }
         */


            /*
            if (sceneCounter % 2 == 0 && sceneCounter != 0)
            {
                int param = SceneManager.GetActiveScene().buildIndex + 1;
                Debug.Log("Block 1: " + param);
                loadNextScene(param);
                sceneCounter++;
            } else if (sceneCounter == 0)
            {
                Debug.Log("Block 2: " + scenes[index]);
                loadNextScene(scenes[index]);
                index++;
                sceneCounter++;
            } else if (sceneCounter == 1)
            {
                int param = SceneManager.GetActiveScene().buildIndex + 1;
                Debug.Log("Block 3: " + param);
                loadNextScene(param);
                sceneCounter++;
            }
            else {
                Debug.Log("Block 4: " + scenes[index]);
                loadNextScene(scenes[index]);
                index++;
                sceneCounter++;
            }*/
            //sceneCounter++;



            if (sceneCounter == noOfScenes)
            {
                Debug.Log("Scenecounter is bigger than number of scenes");
                loadNextScene(26);
                //GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchSchene = false;
               // GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchBool = false;
                //sceneCounter++;
            }

        }
    



           // endSceneReached = false;
        }

    void Shuffle(int[] scenes) {
        int n = scenes.Length;

        while( n > 1) {
            n--;
            int r = _random.Next(n + 1);
            int t = scenes[r];
            scenes[r] = scenes[n];
            scenes[n] = t;
        }
    }

    void loadNextScene(int index) {
        SceneManager.LoadScene(index, LoadSceneMode.Single);
    }

    private void OnApplicationQuit() {
       sr.Close();
    }

}
