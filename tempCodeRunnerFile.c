class Slution {

    private void quickSort(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    private void quickSort(int[] array, int start, int end) {

        if (start < end) {
            int pivot = partition(array, start, end);
            quickSort(array, start, pivot - 1);
            quickSort(array, pivot + 1, end);

        }

    }


    private int partition(int[] array, int start, int end) {

        // 左侧起点：轴点
        int pivot = array[start];

        // 左边界
        // 此处不能为 start + 1, 因为, 最左侧轴点pivot 可能一开始便处于正确的位置无需移动(pivot本身就是最小值);
        // 若初始化 left = start + 1, 则在 最左侧轴点pivot 本身就是最小值的情况下, 由最后一步swap, 则一定会出现错误的交换
        // 导致原本处于正确位置的元素交换到错误的位置
        int left = start;

        // 右边界
        int right = end;

        // 注意：while内为双 while 而非双 if;
        while (left < right) {

            // 轴点设在左侧, right 必须在前; 否则, 若 left 在前, 则 array[left] <= pivot 的取等(==)操作会自动前移(left++),
            // 进而导致当 选取最左侧为 pivot 且 pivot值为最小值时, 会产生错误的交换
            // 由 left < right 控制, left 和 right 双指针绝不会错过
            // 此处必须能取等(==); 否则, 无法继续后移;
            while (array[right] >= pivot && left < right) {
                right--;
            }

            while (array[left] <= pivot && left < right) {
                left++;
            }

            swap(array, left, right);
        }

        // 由于循环结束条件是 left == right; 所以, 以下两处 left 位置均可为 right
        // 由此处的快排交换操作可知, 快排是不稳定的
        swap(array, start, left);
        pivot = left;

        return pivot;

    }


    private void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }


    public void print(int[] array) {
        for (int j: array) {
            System.out.print(j + " ");
        }
    }

    public static void main(String[] args) {
		
		Solution solution = new Soluiton();
		
        int[] array = new int[]{2, 6, 2, 8, 7, 4, 5, 9, 2};
		
        solution.quickSort(array);
        solution.print(array);

    }

}
