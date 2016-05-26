





#include <avr/io.h>
#include <util/delay.h>

const int prog1[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
const int prog2[8] = {0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};
const int allOn = 0xFF;
const int allOff = 0x00;

int main(void){

    while(1){
		DDRC = 0xFF;
        firstProgression();
		secondProgression();
		thirdProgression();
		forthProgression();
    }
}

void firstProgression(){
	int i;

	for(i = 0;i < 8;i++){
		PORTC = prog1[i];
		_delay_ms(250);
	}
	PORTC = allOff;
}

void secondProgression(){
	int i;
	int j;

	for(i = 0;i < 6;i++){

		for(j = 0;j < 8;j++){
			PORTC = prog2[j];
			_delay_ms(55);
		}

		for(j = 6;j >= 0;j--){
			PORTC = prog2[j];
			_delay_ms(55);
		}
		PORTC = allOff;
		_delay_ms(55);
	}
	PORTC = allOff;
}

void thirdProgression(){
	PORTC = allOn;
	_delay_ms(4000);
	PORTC = allOff;
}

void forthProgression(){
	int i;
	for(i = 0;i < 30;i++){
		PORTC = allOn;
		_delay_ms(130);
		PORTC = allOff;
		_delay_ms(130);
	}
}