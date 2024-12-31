#include <iostream>
#include <algorithm>

template<typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
		data = new T[currentCapacity];
	}

	// 얕은 복사 문제로 초기화 리스트에 data를 포함할 수 없다.
	SimpleVector(const SimpleVector& other) : currentCapacity(other.currentCapacity), currentSize(other.currentSize) {
		std::cout << "복사 생성자 호출" << std::endl;

		// 새로운 배열 생성
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
	}

	int capacity() { return currentCapacity; }

	int size() { return currentSize; }

	void pop_back()
	{
		if (currentSize != 0) {
			currentSize--;
		}
		else {
			std::cout << "제거할 원소가 없습니다" << std::endl;
		}
	}

	void push_back(const T& element)
	{
		if (currentCapacity > currentSize) {
			data[currentSize] = element;
			currentSize++;
		}
		else {
			currentCapacity += 5;
			T* newdata = new T[currentCapacity];
			
			for (int i = 0; i < currentSize; i++) {
				newdata[i] = data[i];
			}

			newdata[currentSize] = element;
			currentSize++;
			
			delete[] data;
			data = newdata;
		}
	}

	void resize(int newCapacity)
	{
		if (newCapacity > currentCapacity) {
			currentCapacity = newCapacity;
			T* newdata = new T[currentCapacity];

			for (int i = 0; i < currentSize; i++) {
				newdata[i] = data[i];
			}

			delete[] data;
			data = newdata;

		}
	}

	void sortData()
	{
		//데이터가 배열임을 고려
		std::sort(data, data + currentSize);
	}

	T setter(int index)
	{
		return data[index];
	}


	~SimpleVector() {
		delete[] data;
	}
	
};

// 테스트 코드
int main() {
	SimpleVector<int> vec(3);

	vec.push_back(40);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);

	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	vec.sortData();

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec.setter(i) << ", ";
	}
	std::cout << std::endl;


	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();


	std::cout << vec.size() << std::endl;
	std::cout << vec.capacity() << std::endl;

	
	return 0;
}