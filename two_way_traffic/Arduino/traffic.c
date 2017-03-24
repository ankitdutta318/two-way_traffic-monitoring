#include<stdio.h>
#include <stdbool.h>

// Defining struct
struct traffic_signal {
	bool red;
	bool yellow;
	bool green;
	int cur_density;
	int id;
};

void getCurDensity(struct traffic_signal *ts) {
	printf("\nEnter current density for Traffic signal #%d ", ts->id);
	scanf("%d", &ts->cur_density);
}

void initialize(struct traffic_signal *ts) {
	ts->red = false;
	ts->yellow = false;
	ts->green = false;
}

void setRed (struct traffic_signal *ts) {
	ts->red = true;
	ts->yellow = ts->green = false;
}

void setYellow (struct traffic_signal *ts) {
	ts->yellow = true;
	ts->red = ts->green = false;
}

void setGreen (struct traffic_signal *ts) {
	ts->green = true;
	ts->yellow = ts->red = false;
}

void printStatus(struct traffic_signal *ts) {
	if(ts->red == true) {
		printf("\nTraffic signal #%d : Red", ts->id);
		return;
	}
	if(ts->yellow == true) {
		printf("\nTraffic signal #%d : yellow", ts->id);
		return;
	}
	if(ts->green == true) {
		printf("\nTraffic signal #%d : green", ts->id);
		return;
	}
}

int main() {
	struct traffic_signal TS1, TS2;
	int threshold;
	printf("\nEnter the threshold.");
	scanf("%d", &threshold);
	
	TS1.id = 1;
	TS2.id = 2;
	initialize(&TS1);
	initialize(&TS2);
	
	while(true) {
		getCurDensity(&TS1);
		getCurDensity(&TS2);
	
		if(TS1.cur_density < threshold && TS2.cur_density < threshold) {
			setYellow(&TS1);
			setYellow(&TS2);
			printStatus(&TS1);
			printStatus(&TS2);
		} else {
			if(TS1.cur_density > TS2.cur_density) {
				setGreen(&TS1);
				setRed(&TS2);
				printStatus(&TS1);
				printStatus(&TS2);
			} else {
				setGreen(&TS2);
				setRed(&TS1);
				printStatus(&TS1);
				printStatus(&TS2);
			}
		}	
	} 
	return 0;
}
