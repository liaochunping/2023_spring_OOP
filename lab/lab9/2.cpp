
#include <iostream>

using namespace std;
class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};
int main() {
  NonCopyable a;
    cout << "in main" << endl;
    //NonCopyable b(a);

}
