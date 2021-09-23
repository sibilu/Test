using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine.Audio;

public class setAudioClips1 : MonoBehaviour
{
    public string soundPath;
    public string fileName1 = "Caj1.wav";
    public string fileName2 = "Caj2.wav";
    public string fileName3 = "Caj3.wav";
    public string fileName4 = "Caj4.wav";
    public string fileName5 = "Caj5.wav";
    public string fileName6 = "Caj6.wav";
    public string fileName7 = "Caj7.wav";
    public string fileName8 = "Caj8.wav";
    public string fileName9 = "Caj9.wav";
    public string fileName10 = "Caj10.wav";
    public string fileName11 = "Caj11.wav";
    public string fileName12 = "Caj12.wav";
    public string fileName13 = "Caj13.wav";
    public string fileName14 = "Caj14.wav";
    public string fileName15 = "Caj15.wav";
    public string fileName16 = "Caj16.wav";
    public string fileName17 = "Caj17.wav";
    public string fileName18 = "Caj18.wav";
    public string fileName19 = "Caj19.wav";
    public string fileName20 = "Caj20.wav";
    public string fileName21 = "Caj21.wav";
    public string fileName22 = "Caj22.wav";
    public string fileName23 = "Caj23.wav";
    public string fileName24 = "Caj24.wav";
    public string fileName25 = "Caj25.wav";
    public string fileName26 = "Caj26.wav";
    public string fileName27 = "Caj27.wav";
    public string fileName28 = "Caj28.wav";
    public string fileName29 = "Caj29.wav";
    public string fileName30 = "Caj30.wav";
    public string fileName31 = "Caj31.wav";
    public string fileName32 = "Caj32.wav";
    public string fileName33 = "Caj33.wav";
    public string fileName34 = "Caj34.wav"; 
    public string fileName35 = "Caj35.wav";
    public string fileName36 = "Caj36.wav";
    public string fileName37 = "Caj37.wav";
    public string fileName38 = "Caj38.wav";
    public string fileName39 = "Caj39.wav";
    public string fileName40 = "Caj40.wav";
    public string fileName41 = "Caj41.wav";
    public string fileName42 = "Caj42.wav";
    public string fileName43 = "Caj43.wav";
    public string fileName44 = "Caj44.wav";
    public string fileName45 = "Caj45.wav";
    public string fileName46 = "Caj46.wav";
    public string fileName47 = "Caj47.wav";
    public string fileName48 = "Caj48.wav";

    public AudioClip audioClip1, audioClip2, audioClip3, audioClip4, audioClip5, audioClip6, audioClip7, audioClip8, 
    audioClip9, audioClip10, audioClip11, audioClip12, audioClip13, audioClip14, audioClip15, audioClip16, audioClip17, 
    audioClip18, audioClip19, audioClip20, audioClip21, audioClip22, audioClip23, audioClip24, audioClip25, audioClip26, 
    audioClip27, audioClip28, audioClip29, audioClip30, audioClip31, audioClip32, audioClip33, audioClip34, audioClip35, audioClip36, audioClip37,
    audioClip38, audioClip39, audioClip40, audioClip41, audioClip42, audioClip43, audioClip44, audioClip45, audioClip46, audioClip47, audioClip48;

    AudioSource Speaker1, Speaker2, Speaker3, Speaker4, Speaker5, Speaker6, Speaker7, Speaker8, Speaker9, Speaker10, 
    Speaker11, Speaker12, Speaker13, Speaker14, Speaker15, Speaker16, Speaker17, 
    Speaker18, Speaker19, Speaker20, Speaker21, Speaker22, Speaker23, Speaker24, 
    Speaker25, Speaker26, Speaker27, Speaker28, Speaker29, Speaker30, Speaker31, Speaker32, 
    Speaker33, Speaker34, Speaker35, Speaker36, Speaker37, Speaker38, Speaker39, Speaker40, 
    Speaker41, Speaker42, Speaker43, Speaker44, Speaker45, Speaker46, Speaker47, Speaker48;
    // Start is called before the first frame update
    void Start()
    {

        soundPath = "file://" + Application.streamingAssetsPath + "/Choir/";
        //soundPath = "file://" + "C:/Users/AAU113990/Desktop/CONCERT HALL/Assets/1/";

        Speaker1 = GameObject.Find("speaker1").GetComponent<AudioSource>();
        Speaker2 = GameObject.Find("speaker2").GetComponent<AudioSource>();
        Speaker3 = GameObject.Find("speaker3").GetComponent<AudioSource>();
        Speaker4 = GameObject.Find("speaker4").GetComponent<AudioSource>();
        Speaker5 = GameObject.Find("speaker5").GetComponent<AudioSource>();
        Speaker6 = GameObject.Find("speaker6").GetComponent<AudioSource>();
        Speaker7 = GameObject.Find("speaker7").GetComponent<AudioSource>();
        Speaker8 = GameObject.Find("speaker8").GetComponent<AudioSource>();
        Speaker9 = GameObject.Find("speaker9").GetComponent<AudioSource>();
        Speaker10 = GameObject.Find("speaker10").GetComponent<AudioSource>();
        Speaker11 = GameObject.Find("speaker11").GetComponent<AudioSource>();
        Speaker12 = GameObject.Find("speaker12").GetComponent<AudioSource>();
        Speaker13 = GameObject.Find("speaker13").GetComponent<AudioSource>();
        Speaker14 = GameObject.Find("speaker14").GetComponent<AudioSource>();
        Speaker15 = GameObject.Find("speaker15").GetComponent<AudioSource>();
        Speaker16 = GameObject.Find("speaker16").GetComponent<AudioSource>();
        Speaker17 = GameObject.Find("speaker17").GetComponent<AudioSource>();
        Speaker18 = GameObject.Find("speaker18").GetComponent<AudioSource>();
        Speaker19 = GameObject.Find("speaker19").GetComponent<AudioSource>();
        Speaker20 = GameObject.Find("speaker20").GetComponent<AudioSource>();
        Speaker21 = GameObject.Find("speaker21").GetComponent<AudioSource>();
        Speaker22 = GameObject.Find("speaker22").GetComponent<AudioSource>();
        Speaker23 = GameObject.Find("speaker23").GetComponent<AudioSource>();
        Speaker24 = GameObject.Find("speaker24").GetComponent<AudioSource>();
        Speaker25 = GameObject.Find("speaker25").GetComponent<AudioSource>();
        Speaker26 = GameObject.Find("speaker26").GetComponent<AudioSource>();
        Speaker27 = GameObject.Find("speaker27").GetComponent<AudioSource>();
        Speaker28 = GameObject.Find("speaker28").GetComponent<AudioSource>();
        Speaker29 = GameObject.Find("speaker29").GetComponent<AudioSource>();
        Speaker30 = GameObject.Find("speaker30").GetComponent<AudioSource>();
        Speaker31 = GameObject.Find("speaker31").GetComponent<AudioSource>();
        Speaker32 = GameObject.Find("speaker32").GetComponent<AudioSource>();
        Speaker33 = GameObject.Find("speaker33").GetComponent<AudioSource>();
        Speaker34 = GameObject.Find("speaker34").GetComponent<AudioSource>();
        Speaker35 = GameObject.Find("speaker35").GetComponent<AudioSource>();
        Speaker36 = GameObject.Find("speaker36").GetComponent<AudioSource>();
        Speaker37 = GameObject.Find("speaker37").GetComponent<AudioSource>();
        Speaker38 = GameObject.Find("speaker38").GetComponent<AudioSource>();
        Speaker39 = GameObject.Find("speaker39").GetComponent<AudioSource>();
        Speaker40 = GameObject.Find("speaker40").GetComponent<AudioSource>();
        //Speaker41 = GameObject.Find("speaker41").GetComponent<AudioSource>();
        //Speaker42 = GameObject.Find("speaker42").GetComponent<AudioSource>();
        //Speaker43 = GameObject.Find("speaker43").GetComponent<AudioSource>();
        //Speaker44 = GameObject.Find("speaker44").GetComponent<AudioSource>();
        Speaker45 = GameObject.Find("speaker45").GetComponent<AudioSource>();
        Speaker46 = GameObject.Find("speaker46").GetComponent<AudioSource>();
        Speaker47 = GameObject.Find("speaker47").GetComponent<AudioSource>();
        Speaker48 = GameObject.Find("speaker48").GetComponent<AudioSource>();

        //Debug.Log("sceneName" + SceneManager.GetActiveScene().name);
        
        StartCoroutine(LoadAudio());

    }


    void Update(){

        
        Speaker1.clip = audioClip1;
        Speaker2.clip = audioClip2;
        Speaker3.clip = audioClip3;
        Speaker4.clip = audioClip4;
        Speaker5.clip = audioClip5;
        Speaker6.clip = audioClip6;
        Speaker7.clip = audioClip7;
        Speaker8.clip = audioClip8;
        Speaker9.clip = audioClip9;
        Speaker10.clip = audioClip10;
        Speaker11.clip = audioClip11;
        Speaker12.clip = audioClip12;
        Speaker13.clip = audioClip13;
        Speaker14.clip = audioClip14;
        Speaker15.clip = audioClip15;
        Speaker16.clip = audioClip16;
        Speaker17.clip = audioClip17;
        Speaker18.clip = audioClip18;
        Speaker19.clip = audioClip19;
        Speaker20.clip = audioClip20;
        Speaker21.clip = audioClip21;
        Speaker22.clip = audioClip22;
        Speaker23.clip = audioClip23;
        Speaker24.clip = audioClip24;
        Speaker25.clip = audioClip25;
        Speaker26.clip = audioClip26;
        Speaker27.clip = audioClip27;
        Speaker28.clip = audioClip28;
        Speaker29.clip = audioClip29;
        Speaker30.clip = audioClip30;
        Speaker31.clip = audioClip31;
        Speaker32.clip = audioClip32;
        Speaker33.clip = audioClip33;
        Speaker34.clip = audioClip34;
        Speaker35.clip = audioClip35;
        Speaker36.clip = audioClip36;
        Speaker37.clip = audioClip37;
        Speaker38.clip = audioClip38;
        Speaker39.clip = audioClip39;
        Speaker40.clip = audioClip40;
        //Speaker41.clip = audioClip41;
        //Speaker42.clip = audioClip42;
        //Speaker43.clip = audioClip43;
        //Speaker44.clip = audioClip44;
        Speaker45.clip = audioClip45;
        Speaker46.clip = audioClip46;
        Speaker47.clip = audioClip47;
        Speaker48.clip = audioClip48;

        if (Input.GetKeyDown("space"))
        {
            
            Debug.Log("Audio Started");
            Debug.Log(Speaker1.isPlaying);
            Speaker1.PlayDelayed(2);
            Debug.Log(Speaker1.isPlaying);
            Speaker2.PlayDelayed(2);
            Speaker3.PlayDelayed(2);
            Speaker4.PlayDelayed(2);
            Speaker5.PlayDelayed(2);
            Speaker6.PlayDelayed(2);
            Speaker7.PlayDelayed(2);
            Speaker8.PlayDelayed(2);
            Speaker9.PlayDelayed(2);
            Speaker10.PlayDelayed(2);
            Speaker11.PlayDelayed(2);
            Speaker12.PlayDelayed(2);
            Speaker13.PlayDelayed(2);
            Speaker14.PlayDelayed(2);
            Speaker15.PlayDelayed(2);
            Speaker16.PlayDelayed(2);
            Speaker17.PlayDelayed(2);
            Speaker18.PlayDelayed(2);
            Speaker19.PlayDelayed(2);
            Speaker20.PlayDelayed(2);
            Speaker21.PlayDelayed(2);
            Speaker22.PlayDelayed(2);
            Speaker23.PlayDelayed(2);
            Speaker24.PlayDelayed(2);
            Speaker25.PlayDelayed(2);
            Speaker26.PlayDelayed(2);
            Speaker27.PlayDelayed(2);
            Speaker28.PlayDelayed(2);
            Speaker29.PlayDelayed(2);
            Speaker30.PlayDelayed(2);
            Speaker31.PlayDelayed(2);
            Speaker32.PlayDelayed(2);
            Speaker33.PlayDelayed(2);
            Speaker34.PlayDelayed(2);
            Speaker35.PlayDelayed(2);
            Speaker36.PlayDelayed(2);
            Speaker37.PlayDelayed(2);
            Speaker38.PlayDelayed(2);
            Speaker39.PlayDelayed(2);
            Speaker40.PlayDelayed(2);
            //Speaker41.PlayDelayed(2);
            //Speaker42.PlayDelayed(2);
            //Speaker43.PlayDelayed(2);
            //Speaker44.PlayDelayed(2);
            Speaker45.PlayDelayed(2);
            Speaker46.PlayDelayed(2);
            Speaker47.PlayDelayed(2);
            Speaker48.PlayDelayed(2); 
        }

    }
    // Update is called once per frame
    
    private IEnumerator LoadAudio(){

        WWW request1 = GetAudioFromFile(soundPath, fileName1);
        yield return request1;
        audioClip1 = request1.GetAudioClip();
        audioClip1.name = fileName1;

        WWW request2 = GetAudioFromFile(soundPath, fileName2);
        yield return request2;
        audioClip2 = request2.GetAudioClip();
        audioClip2.name = fileName2;

        WWW request3 = GetAudioFromFile(soundPath, fileName3);
        yield return request3;
        audioClip3 = request3.GetAudioClip();
        audioClip3.name = fileName3;

        WWW request4 = GetAudioFromFile(soundPath, fileName4);
        yield return request4;
        audioClip4 = request4.GetAudioClip();
        audioClip4.name = fileName4;

        WWW request5 = GetAudioFromFile(soundPath, fileName5);
        yield return request5;
        audioClip5 = request5.GetAudioClip();
        audioClip5.name = fileName5;

        WWW request6 = GetAudioFromFile(soundPath, fileName6);
        yield return request6;
        audioClip6 = request6.GetAudioClip();
        audioClip6.name = fileName6;

        WWW request7 = GetAudioFromFile(soundPath, fileName7);
        yield return request7;
        audioClip7 = request7.GetAudioClip();
        audioClip7.name = fileName7;

        WWW request8 = GetAudioFromFile(soundPath, fileName8);
        yield return request8;
        audioClip8 = request8.GetAudioClip();
        audioClip8.name = fileName8;

        WWW request9 = GetAudioFromFile(soundPath, fileName9);
        yield return request9;
        audioClip9 = request9.GetAudioClip();
        audioClip9.name = fileName9;

        WWW request10 = GetAudioFromFile(soundPath, fileName10);
        yield return request10;
        audioClip10 = request10.GetAudioClip();
        audioClip10.name = fileName10;

         WWW request11 = GetAudioFromFile(soundPath, fileName11);
        yield return request11;
        audioClip11 = request11.GetAudioClip();
        audioClip11.name = fileName11;

        WWW request12 = GetAudioFromFile(soundPath, fileName12);
        yield return request12;
        audioClip12 = request12.GetAudioClip();
        audioClip12.name = fileName12;

        WWW request13 = GetAudioFromFile(soundPath, fileName13);
        yield return request13;
        audioClip13 = request13.GetAudioClip();
        audioClip13.name = fileName13;

        WWW request14 = GetAudioFromFile(soundPath, fileName14);
        yield return request14;
        audioClip14 = request14.GetAudioClip();
        audioClip14.name = fileName14;

        WWW request15 = GetAudioFromFile(soundPath, fileName15);
        yield return request15;
        audioClip15 = request15.GetAudioClip();
        audioClip15.name = fileName15;

        WWW request16 = GetAudioFromFile(soundPath, fileName16);
        yield return request16;
        audioClip16 = request16.GetAudioClip();
        audioClip16.name = fileName16;

        WWW request17 = GetAudioFromFile(soundPath, fileName17);
        yield return request17;
        audioClip17 = request17.GetAudioClip();
        audioClip17.name = fileName17;

        WWW request18 = GetAudioFromFile(soundPath, fileName18);
        yield return request18;
        audioClip18 = request18.GetAudioClip();
        audioClip18.name = fileName18;

        WWW request19 = GetAudioFromFile(soundPath, fileName19);
        yield return request19;
        audioClip19 = request19.GetAudioClip();
        audioClip19.name = fileName19;

        WWW request20 = GetAudioFromFile(soundPath, fileName20);
        yield return request20;
        audioClip20 = request20.GetAudioClip();
        audioClip20.name = fileName20;

         WWW request21 = GetAudioFromFile(soundPath, fileName21);
        yield return request12;
        audioClip21 = request21.GetAudioClip();
        audioClip21.name = fileName21;

        WWW request22 = GetAudioFromFile(soundPath, fileName22);
        yield return request22;
        audioClip22 = request22.GetAudioClip();
        audioClip22.name = fileName22;

        WWW request23 = GetAudioFromFile(soundPath, fileName23);
        yield return request23;
        audioClip23 = request23.GetAudioClip();
        audioClip23.name = fileName23;

        WWW request24 = GetAudioFromFile(soundPath, fileName24);
        yield return request24;
        audioClip24 = request24.GetAudioClip();
        audioClip24.name = fileName24;

        WWW request25 = GetAudioFromFile(soundPath, fileName25);
        yield return request25;
        audioClip25 = request25.GetAudioClip();
        audioClip25.name = fileName25;

        WWW request26 = GetAudioFromFile(soundPath, fileName26);
        yield return request26;
        audioClip26 = request26.GetAudioClip();
        audioClip26.name = fileName26;

        WWW request27 = GetAudioFromFile(soundPath, fileName27);
        yield return request27;
        audioClip27 = request27.GetAudioClip();
        audioClip27.name = fileName27;

        WWW request28 = GetAudioFromFile(soundPath, fileName28);
        yield return request28;
        audioClip28 = request28.GetAudioClip();
        audioClip28.name = fileName28;

        WWW request29 = GetAudioFromFile(soundPath, fileName29);
        yield return request29;
        audioClip29 = request29.GetAudioClip();
        audioClip29.name = fileName29;

        WWW request30 = GetAudioFromFile(soundPath, fileName30);
        yield return request30;
        audioClip30 = request30.GetAudioClip();
        audioClip30.name = fileName30;

        WWW request31 = GetAudioFromFile(soundPath, fileName31);
        yield return request31;
        audioClip31 = request31.GetAudioClip();
        audioClip31.name = fileName31;

        WWW request32 = GetAudioFromFile(soundPath, fileName32);
        yield return request32;
        audioClip32 = request32.GetAudioClip();
        audioClip32.name = fileName32;

         WWW request33 = GetAudioFromFile(soundPath, fileName33);
        yield return request33;
        audioClip33 = request33.GetAudioClip();
        audioClip33.name = fileName33;

        WWW request34 = GetAudioFromFile(soundPath, fileName34);
        yield return request34;
        audioClip34 = request34.GetAudioClip();
        audioClip34.name = fileName34;

        WWW request35 = GetAudioFromFile(soundPath, fileName35);
        yield return request35;
        audioClip35 = request35.GetAudioClip();
        audioClip35.name = fileName35;

        WWW request36 = GetAudioFromFile(soundPath, fileName36);
        yield return request36;
        audioClip36 = request36.GetAudioClip();
        audioClip36.name = fileName36;

        WWW request37 = GetAudioFromFile(soundPath, fileName37);
        yield return request37;
        audioClip37 = request37.GetAudioClip();
        audioClip37.name = fileName37;

        WWW request38 = GetAudioFromFile(soundPath, fileName38);
        yield return request38;
        audioClip38 = request38.GetAudioClip();
        audioClip38.name = fileName38;

        WWW request39 = GetAudioFromFile(soundPath, fileName39);
        yield return request39;
        audioClip39 = request39.GetAudioClip();
        audioClip39.name = fileName39;

        WWW request40 = GetAudioFromFile(soundPath, fileName40);
        yield return request40;
        audioClip40 = request40.GetAudioClip();
        audioClip40.name = fileName40;

        WWW request41 = GetAudioFromFile(soundPath, fileName41);
        yield return request41;
        audioClip41 = request41.GetAudioClip();
        audioClip41.name = fileName41;

        WWW request42 = GetAudioFromFile(soundPath, fileName42);
        yield return request42;
        audioClip42 = request42.GetAudioClip();
        audioClip42.name = fileName42;

         WWW request43 = GetAudioFromFile(soundPath, fileName43);
        yield return request43;
        audioClip43 = request43.GetAudioClip();
        audioClip43.name = fileName43;

        WWW request44 = GetAudioFromFile(soundPath, fileName44);
        yield return request44;
        audioClip44 = request44.GetAudioClip();
        audioClip44.name = fileName44;

        WWW request45 = GetAudioFromFile(soundPath, fileName45);
        yield return request45;
        audioClip45 = request45.GetAudioClip();
        audioClip45.name = fileName45;

        WWW request46 = GetAudioFromFile(soundPath, fileName46);
        yield return request46;
        audioClip46 = request46.GetAudioClip();
        audioClip46.name = fileName46;

        WWW request47 = GetAudioFromFile(soundPath, fileName47);
        yield return request47;
        audioClip47 = request47.GetAudioClip();
        audioClip47.name = fileName47;

        WWW request48 = GetAudioFromFile(soundPath, fileName48);
        yield return request48;
        audioClip48 = request48.GetAudioClip();
        audioClip48.name = fileName48;
        
    }

    private WWW GetAudioFromFile(string path, string filename){

        string audioToLoad = string.Format(path + "{0}", filename);
        WWW request = new WWW(audioToLoad);
        return request;

    }


}
