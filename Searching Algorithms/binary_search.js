var n = 5,
  k = 5;
var arr = [1, 2, 3, 4, 5];

console.log(binarySearch(arr, n, k));

function binarySearch(arr, n, k) {
  var first = 0,
    last = n - 1;
  while (first <= last) {
    var mid = Math.floor((first + last) / 2);
    if (arr[mid] === k) return mid;
    else if (arr[mid] > k) last = mid - 1;
    else if (arr[mid] < k) first = mid + 1;
  }
  return -1;
}
