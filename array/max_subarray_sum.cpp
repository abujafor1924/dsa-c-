#include <iostream>
using namespace std;

// ক্যাডেনের অ্যালগরিদম (Kadane's Algorithm)
int maximum_subarray_sum(int arr[], int size)
{
  int  cs = 0;        // বর্তমান সাবঅ্যারে সাম (Current Subarray Sum)
  int largest = 0;    // সর্বোচ্চ সাবঅ্যারে সাম (Maximum Subarray Sum)

  for (int i = 0; i < size; i++)
  {
    cs = cs + arr[i];  // বর্তমান এলিমেন্ট যোগ করুন
    if (cs < 0)        // যদি বর্তমান যোগফল নেগেটিভ হয়
    {
        cs = 0;        // বর্তমান যোগফল রিসেট করুন (নেগেটিভ যোগফল বাদ দিন)
    }
    
     largest = max(largest, cs);  // সর্বোচ্চ মান আপডেট করুন
  }
  return largest;      // সর্বোচ্চ সাবঅ্যারে সাম রিটার্ন করুন
}

int main()
{
     int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
     int size = sizeof(arr) / sizeof(arr[0]);  // অ্যারের সাইজ নির্ণয়
     int result = maximum_subarray_sum(arr, size);  // ফাংশন কল
     cout << "Maximum subarray sum is: " << result << endl;
     return 0;
}



// ধাপ ১: cs = -2 → cs = 0, largest = 0
// ধাপ ২: cs = 1 → largest = 1  
// ধাপ ৩: cs = -2 → cs = 0, largest = 1
// ধাপ ৪: cs = 4 → largest = 4
// ধাপ ৫: cs = 3 → largest = 4
// ধাপ ৬: cs = 5 → largest = 5
// ধাপ ৭: cs = 6 → largest = 6
// ধাপ ৮: cs = 1 → largest = 6
// ধাপ ৯: cs = 5 → largest = 6