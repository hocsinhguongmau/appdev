//constants definition
#define RATE 16000//samples per second

//data sturctures
struct WAVHDR{
	char ChunkID[4];//it has to be "RIFF"
	int ChunkSize;//4 byte number
	char Format[4];//it has to be "WAVE"
	
	char Subchunk1ID[4];//"fmt "
	int Subchunk1Size;//PCM = 16
	short AudioFormat; //should be 1
	short NumChannels;//should be 1 for mono
	int SamleRate;//16000
	int ByteRate;//16000*Numchannels*BitsPerSample/8
	short BlockAlign;//NumChannels*BitsPerSaple/8
	short BitsPersample;//in our app, 16 (S16_LE)

	char SubChunk2ID[4];//"data"
	int SubChunk2Size;
};

//function declarations 
