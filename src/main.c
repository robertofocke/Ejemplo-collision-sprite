#include <genesis.h>
#include "recursos.h"
struct personaje {
int posy;
int posx;
int width;
int height;
Sprite *scorpion_sprite;    
}miPersonaje, enemigo;
int main()
{
    
    miPersonaje.posy=70;
    miPersonaje.posx=0;
    miPersonaje.width=64;
    miPersonaje.height=80;
    enemigo.posx=140;
    enemigo.posy=40;
    enemigo.width=64;
    enemigo.height=80;

    SPR_init(0);
    VDP_setPalette(PAL1,scorpion.palette->data);
    miPersonaje.scorpion_sprite=SPR_addSprite(&scorpion,miPersonaje.posx,miPersonaje.posy,TILE_ATTR(PAL1,FALSE,FALSE,FALSE));
    SPR_setAnim(miPersonaje.scorpion_sprite,0);

    enemigo.scorpion_sprite=SPR_addSprite(&scorpion,enemigo.posx,enemigo.posy,TILE_ATTR(PAL1,FALSE,FALSE,FALSE));
    

    while(1)
    {
        SPR_update();
        UpdatePersonaje();
        checkcoll();
        SYS_doVBlankProcess();
    }
    return (0);
}
void UpdatePersonaje(){

    int value= JOY_readJoypad(JOY_1);
        if (value & BUTTON_RIGHT){
            SPR_setPosition(miPersonaje.scorpion_sprite,miPersonaje.posx++,miPersonaje.posy);
        } 
        else if(value & BUTTON_LEFT){
            SPR_setPosition(miPersonaje.scorpion_sprite,miPersonaje.posx--,miPersonaje.posy);

        }  else if(value & BUTTON_UP){
            SPR_setPosition(miPersonaje.scorpion_sprite,miPersonaje.posx,miPersonaje.posy++);

        }  else if(value & BUTTON_DOWN){
            SPR_setPosition(miPersonaje.scorpion_sprite,miPersonaje.posx,miPersonaje.posy--);

        }      
    
}
void checkcoll(){
   if(miPersonaje.posx < enemigo.posx +enemigo.width &&
    miPersonaje.posx +miPersonaje.width > enemigo.posx &&
    miPersonaje.posy < enemigo.posy + enemigo.height &&
    miPersonaje.height + miPersonaje.posy > enemigo.posy)
    {
        VDP_drawText("colision",0,20);
        VDP_clearTextLine(0);
    } else{
        VDP_clearTextLine(20);
        VDP_drawText("NO colision",0,0);
    }

}