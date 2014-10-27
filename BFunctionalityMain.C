/*******************************
 * Author:		C2C Kevin Cabusora
 * Created:		22 Oct 2014
 * Description:	Lab 4: Main Functionality
 *******************************/

#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void	moveDelay();
extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)


void main() {

	unsigned char	x, y, xDirection, yDirection;
	unsigned int	i;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	//button_press = FALSE;					; We don't use button_press in B


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	xDirection=1;	yDirection=1;
	drawBlock(y,x);

	while(1) {
		if (xDirection == 0){
			x--;
			if (x<=0) xDirection=1;
		}
		if (xDirection == 1){
			x++;
			if (x>=11) xDirection=0; // Max limit for screen, got this by messing around and finding closest to screen wall
		}
		if (yDirection == 0){
			y--;
			if (y<=0) yDirection=1;
		}
		if (yDirection == 1){
			y++;
			if (y>=7) yDirection=0; // Max limit for screen, got this by messing around and finding closest to screen wall
		}

				clearDisplay();
				drawBlock(y,x);
				for(i = 0; i<10; i++){ // Loops the process
					moveDelay();}
			}
		}
