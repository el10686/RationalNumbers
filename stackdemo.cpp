#include <iostream>

using namespace std;

template <typename T>
class stack{
	public:
		stack (int size): n(size), array(new T[size]), head(-1) {}

		stack (const stack &s): n(s.n), array(new T[s.n]), head(s.head) {
			for (int i=0; i<=head; i++){
				array[i] = s.array[i];
			}
		}

		~stack() {
			delete[](array);
		}

		const stack & operator = (const stack &s){
			delete[](array);
			array = new T[s.n];
			head = s.head;
			for (int i=0; i<=s.head; i++){
				array[i] = s.array[i];
			}
			return *this;
		}

		bool empty(){
			return head == -1;
		}

		void push (const T &x){
			if (head == n-1){
				cout << "Stack full, pushed nothing..\n";
				return;
			}
			else{
				head++;
				array[head] = x;
			}
		}

		T pop(){
			if (empty()){
				cout << "Stack empty, can't pop, exiting..\n";
				exit(EXIT_FAILURE);
			}
			else{
				head--;
				return array[head+1];
			}
		}

		int size(){
			if (head == -1){
				return 0;
			}
			else{
				return head + 1;
			}
		}

		friend ostream & operator << (ostream &out, const stack &s){
			out << "[";
			for (int i = 0; i <= s.head; i++){
				if (i == s.head){
					out << s.array[i];
				}
				else {
					out << s.array[i] << ", ";
				}
			}
			out << "]";
			return out;
		}

	private:
		int n;
		T *array;
		int head;
};
