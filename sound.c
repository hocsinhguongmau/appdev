#include <stdio.h>
#include <math.h>
#include "sound.h"
void displayWAVDATA(short s[]){
        double rms[80];//because we have 16000 samples, therefore array 200 samples makes one RMS
        int i, j; //nested loop counters
        short *ptr = s;//use pointer point to the beginning of the samples
        for(i=0;i<80;i++){
                double sum = 0;//initialize the sum
                for(j=0;j<200;j++){
                        sum += (*ptr)*(*ptr);
                        ptr++;
                }
                rms[i] = sqrt(sum/200);
                printf("RMS[%d] = %f\n", i, rms[i]);
        }
}

//this function takes 1 second of sample (16000 in out case) and calculate 80 pieces of RMS value, 
//and then turn these values into decibels, and display them as a bar chart
void showID(char *name, char *value){
	printf("%s: ", name);
	for(int i=0; i<4; i++) {
		printf("%c", value[i]);
	}
	puts("");
}

//function definition
void displayWAVHDR(struct WAVHDR h){
	showID("Chunk ID", h.ChunkID);
	printf("Chunk size: %d\n", h.ChunkSize);
	showID("Format", h.Format);
	showID("Subchunk1 ID", h.Subchunk1ID);
	printf("Subchunk1 size: %d\n", h.Subchunk1Size);
	printf("Audio format: %d\n", h.AudioFormat);
	printf("Num Channels: %d\n", h.NumChannels);
 	printf("Sample rate: %d\n", h.SampleRate);
 	printf("Byte rate: %d\n", h.ByteRate);
 	printf("Block align: %d\n", h.BlockAlign);
 	printf("Bits per sample: %d\n", h.BitsPersample);
	showID("Subchunk 2 ID:", h.Subchunk2ID);
	printf("Subchunk 2 size: %d\n", h.Subchunk2Size);
}
