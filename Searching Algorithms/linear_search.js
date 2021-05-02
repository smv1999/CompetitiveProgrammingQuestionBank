var n = 5,
  k = 5;
var arr = [1, 2, 3, 4, 5];

console.log(linearSearch(arr, n, k));

function linearSearch(arr, n, k) {
  for (var index = 0; index < n; index++) {
    if (arr[index] == k) return index;
  }
  return -1;
}
