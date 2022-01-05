#include<iostream>
using namespace std;

class shark{
    public:
        static shark* sharkBoard[101][101];
        static shark* sharkBoard2[101][101];
        static int R,C;
        int r,c,s,d,z;
        shark(int r,int c,int s,int d,int z){
            this->r = r;
            this->c = c;
            this->s = s;
            this->d = d;
            this->z = z;
        }
        void move(){
            r = d>2 ? r : r+(d*2-3)*s;
            c = d<3 ? c : c+(7-d*2)*s;
			r=r%((R-1)*2);
            c=c%((C-1)*2);
            if(r<=0) r+=(R-1)*2;
            if(c<=0) c+=(C-1)*2;
            if(r>R){
            	r=2*R-r;
            	d=d%2==0?d-1:d+1;
			}
			if(c>C){
				c=2*C-c;
			   	d=d%2==0?d-1:d+1;

			}
            
            if(sharkBoard2[r][c]){
            	if(sharkBoard2[r][c]->z < this->z){
            		sharkBoard2[r][c] = this;
				}
			}
			else{
					
				sharkBoard2[r][c]=this;
			}
        }
        static void update(){
        	for(int i=1;i<=R;i++){
        		for(int j=1;j<=C;j++){
        			sharkBoard[i][j] = sharkBoard2[i][j];
        			sharkBoard2[i][j] = nullptr;
				}
			}
		}
};
shark* shark::sharkBoard[101][101];
shark* shark::sharkBoard2[101][101];
int shark::R;
int shark::C;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int R,C,M;
    int sum=0;
    cin>>R>>C>>M;
    shark::R=R;
    shark::C=C;
    for(int i=0;i<M;i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        shark::sharkBoard[r][c] = new shark(r,c,s,d,z);
    }
    for(int i=1;i<=C;i++){
    	for(int j=1;j<=R;j++){
    		if(shark::sharkBoard[j][i]){
    			sum+=shark::sharkBoard[j][i]->z;
    			shark::sharkBoard[j][i]=nullptr;
    			break;
			}
		}
		for(int k=1;k<=R;k++){
			for(int j=1;j<=C;j++){
				if(shark::sharkBoard[k][j]){
					shark::sharkBoard[k][j]->move();
				}
			}
		}
		shark::update();/*
		for(int k=1;k<=R;k++){
			for(int j=1;j<=C;j++){
				if(shark::sharkBoard[k][j]){
					cout<<shark::sharkBoard[k][j]->z<<" ";
				}
				else{
					cout<<"0 ";
				}
			}
			cout<<'\n';
		}
		cout<<'\n';*/
	}
    cout<<sum;
}
