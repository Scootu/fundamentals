#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle(double width = 0.0, double height = 0.0) :
			width(width), height(height) {
	}
	double ComputeArea() const {
		// CE: function is cont, can't change member variables
		// width = 1;
		return width * height;
	}
	// Setters & Getters
	double GetHeight() const {
		return height;
	}
	void SetHeight(double height) {
		this->height = height;
	}
	double GetWidth() const {
		return width;
	}
	void SetWidth(double width) {
		this->width = width;
	}
};

int main() {
	Rectangle r10(2, 3);
	r10.ComputeArea();
	r10.SetWidth(10);

	const Rectangle r2(4, 5);
	r2.ComputeArea();
	// CE: const object can't call non-const member function
	// r2.SetWidth(10);
    const Rectangle* r1 = &r2; // ✅ Data const, pointer non-const
    // Rectangle* const r3 = r2; ❌ ERROR: Can't assign const object to non-const pointer
    const Rectangle* const r4 = &r2; // ✅ Pointer and data both const
	return 0;
}