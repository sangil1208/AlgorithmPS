#define MAX_SIZE 1000

using namespace std;

template <typename T, typename C>
struct PQ {
	T heap[MAX_SIZE];
	int hn = 0;
	C cmp;

	void clear() {
		hn = 0;
	}

	void push(T data) {
		heap[hn] = data;

		int cur = hn;
		while (cur > 0 && cmp(heap[cur], heap[(cur - 1) / 2])) {
			T tmp = heap[cur];
			heap[cur] = heap[(cur - 1) / 2];
			heap[(cur - 1) / 2] = tmp;

			cur = (cur - 1) / 2;
		}

		++hn;
	}

	T top() { return heap[0]; }

	void pop() {
		heap[0] = heap[--hn];
		int cur = 0;

		while (cur * 2 + 1 < hn) {
			int next;
			if (cur * 2 + 2 == hn) { // ??
				next = cur * 2 + 1;
			}
			else {
				next = cmp(heap[cur * 2 + 1], heap[cur * 2 + 2]) ? cur * 2 + 1 : cur * 2 + 2;
			}

			if (cmp(heap[cur], heap[next])) break;

			T tmp = heap[cur];
			heap[cur] = heap[next];
			heap[next] = tmp;

			cur = next;
		}
	}
};