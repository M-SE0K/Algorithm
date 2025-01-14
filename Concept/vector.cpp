//gpt
#include <iostream>

template <typename T>
class Vector
{
private:
    T* data;          // 실제 데이터를 저장하는 배열
    size_t capacity;   // 벡터의 총 용량
    size_t size;       // 벡터에 저장된 요소의 개수

    // 용량을 두 배로 늘리는 함수
    void resize() {
        capacity *= 2;             // 용량을 두 배로 늘림
        T* temp = new T[capacity]; // 새로운 배열 할당

        // 기존 데이터를 새로운 배열로 복사
        for (size_t i = 0; i < size; i++) {
            temp[i] = data[i];
        }

        delete[] data;  // 기존 데이터 삭제
        data = temp;    // 새로운 데이터 배열로 교체
    }

public:
    // 생성자: 초기 용량 설정
    Vector() {
        size = 0;
        capacity = 1;
        data = new T[capacity]; // 초기 배열 크기는 1로 설정
    }

    // 소멸자: 메모리 해제
    ~Vector() {
        delete[] data;
    }

    // 요소 추가 (push_back)
    void push_back(const T& value) {
        // 용량이 꽉 차면 두 배로 늘림
        if (size == capacity) {
            resize();
        }

        data[size] = value; // 새로운 값 추가
        size++;             // 사이즈 증가
    }

    // 요소 삭제 (pop_back)
    void pop_back() {
        if (size > 0) {
            size--; // 마지막 요소 제거
        }
    }

    // 특정 인덱스에 있는 요소를 반환 (연산자 오버로딩)
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // 현재 벡터에 저장된 요소의 개수를 반환 (size 함수)
    size_t getSize() const {
        return size;
    }

    // 벡터의 용량을 반환 (capacity 함수)
    size_t getCapacity() const {
        return capacity;
    }

    // 벡터가 비어있는지 확인하는 함수
    bool isEmpty() const {
        return size == 0;
    }

    // 모든 요소를 출력하는 함수
    void display() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
