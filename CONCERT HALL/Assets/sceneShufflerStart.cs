using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using System.IO;

public class sceneShufflerStart : MonoBehaviour
{

    public GameObject[] myObject;
    public int index = 0;
    public int sceneCounter = 0;
    public int startSceneIndex = 0;
    private int[] scenes = new int[12];
    int noOfScenes = 25;

    public bool startScenes;

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
       
        int j = 0;
        sr = new StreamWriter(path, true);
        for (int i = 0; i < noOfScenes; i++) {
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

        startScenes = true;
        myObject = GameObject.FindGameObjectsWithTag("sceneShuffling");
        DontDestroyOnLoad(this.gameObject);
        
    }

    // Update is called once per frame
    void Update() {
        if (startScenes == true && GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchSchene == true && GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchBool == true) {

                if (startSceneIndex == 0) {
                  startSceneIndex++;
                }

                if (startSceneIndex == 1) {
                    loadNextScene(25);
                    sceneCounter = 0;
                    startScenes = false;
                }
        }

        //sceneCounter = 0;

        if (startScenes == false && GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchSchene == true && GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchBool == true && sceneCounter < noOfScenes) {
            Debug.Log("sceneCounter: " + sceneCounter);


                if (GameObject.Find("Pan Unit").GetComponent<AudioPanning>().tempTime != -2.0f) {
                    timeToWrite = GameObject.Find("Pan Unit").GetComponent<AudioPanning>().tempTime;
                    sr.WriteLine("Scene: " + SceneManager.GetActiveScene().name + " time: " + timeToWrite);
                    Debug.Log("Scene: " + SceneManager.GetActiveScene().name + " time: " + timeToWrite);
                }

            if (sceneCounter == 0)
            {
                loadNextScene(scenes[index]);
            }


            if (sceneCounter % 2 == 0) {
                    loadNextScene(SceneManager.GetActiveScene().buildIndex + 1);
                }
                else {
                    loadNextScene(scenes[index]);
                    index++;
                }
                sceneCounter++;
            

            if (sceneCounter == noOfScenes)
            {
                GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchSchene = false;
                GameObject.Find("Pan Unit").GetComponent<AudioPanning>().switchBool = false;
                endSceneReached = true;
                //sceneCounter++;
            }

            if (endSceneReached)
            {
                loadNextScene(26);
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
