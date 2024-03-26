#include <SDL2/SDL_audio.h>
#include <SDL2/SDL.h>
#include <unistd.h>

typedef struct {
    SDL_AudioSpec spec;
    int freq;
    int t;
    int err;
    int newfreq;
    int newt;
    Uint8 v;
} udata_t;
static udata_t uData;

static void fill_audio(void *udata, Uint8 *stream, int len)
{
    udata_t * const d= udata;
    while(len--) {
        if(!d->t) {
            if(d->newt) d->t = d->newt;
            d->freq = d->newfreq;
            d->newt = 0;
        }
        if(d->t) {
            d->t--;
            d->err += d->freq;
            if(d->err >= d->spec.freq) {
                d->err -= d->spec.freq*2;
                d->v= ~d->v;
            }
        } else if(!len) {
            SDL_PauseAudio(1);
        }
        *stream++ = d->v;
    }
}
void Beep(int Hz, int msec)
{   
    while(uData.newt) {
        usleep((uData.t*1000+uData.spec.freq-1)/uData.spec.freq*1000);
    }
    uData.newfreq= Hz*4;
    uData.newt= uData.spec.freq*msec/1000;
    if(!uData.t) SDL_PauseAudio(0);
}
void wait_audio()
{
    while(uData.newt || uData.t) {
        usleep((uData.t*1000+uData.spec.freq-1)/uData.spec.freq*1000);
    }
}
void init_audio()
{
    SDL_AudioSpec wanted;

    /* Set the audio format */
    wanted.freq = 65535;
    wanted.format = AUDIO_U8;
    wanted.channels = 1;    /* 1 = mono, 2 = stereo */
    wanted.samples = 1024;  /* Good low-latency value for callback */
    wanted.callback = fill_audio;
    wanted.userdata = &uData;

    /* Open the audio device, forcing the desired format */
    if ( SDL_OpenAudio(&wanted, &uData.spec) < 0 ) {
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
        exit(1);
    }

    uData.err= uData.spec.freq;
}
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_AUDIO);
    init_audio();
    
    Beep(500, 100);
    Beep(200, 200);

    wait_audio();
    return 0;
}
