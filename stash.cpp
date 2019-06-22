#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int sizes[5] = {1, 4, 4, 8, 1};
    
    void* stash = malloc(18);
    
    unsigned char* c = (unsigned char*)stash;
    
    *c = 88;
    c++;
    
    *c = 192;
    c++;
    
    *c = 7;
    c++;
    
    *c = 0;
    c++;
    
    *c = 0;
    c++;
    
    *c = 21;
    c++;
    
    *c = 205;
    c++;
    
    *c = 91;
    c++;
    
    *c = 7;
    c++;

    *c = 162;
    c++;
    
    *c = 48;
    c++;
    
    *c = 210;
    c++;
    
    *c = 178;
    c++;
    
    *c = 244;
    c++;
    
    *c = 16;
    c++;
    
    *c = 34;
    c++;
    
    *c = 17;
    c++;
    
    *c = 80;
    
    cout << "The stash contents are: " << endl;
    
    
    // Insert your code here...
	unsigned char* x = (unsigned char*)stash;

	for (int i = 0; i < 5; i++) {
		if (sizes[i] == 1) {
			cout << (char)(*x) << endl;
			x++;
		}
		else if (sizes[i] == 4) {
			cout << (int)(*x) << endl;
			x++;
			x++;
			x++;
			x++;
		}
		else if (sizes[i] == 8) {
			cout << (int)(*x) << endl;
			x++;
			x++;
			x++;
			x++;
			x++;
			x++;
			x++;
			x++;
		}
	}
    
    
    free(stash);
    
    return 0;
}
