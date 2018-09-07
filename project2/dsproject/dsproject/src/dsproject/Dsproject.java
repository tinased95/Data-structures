/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dsproject;

import java.util.Arrays;
import java.util.Random;

/**
 *
 * 
 */
public class Dsproject {

    public static int partition(int a[], int p, int r) {
        int i, j, pivot, temp;
        pivot = a[p];
        i = p;
        j = r;
        while (true) {
            while (a[i] < pivot && a[i] != pivot) {
                i++;
            }
            while (a[j] > pivot && a[j] != pivot) {
                j--;
            }
            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } else {
                return j;
            }
        }
    }

    public static void quicksort(int a[], int p, int r) {
        if (p < r) {
            int q;
            q = partition(a, p, r);
            quicksort(a, p, q);
            quicksort(a, q + 1, r);
        }
    }

    public static void insertionsort(int arr[], int length) {
        int j, temp;

        for (int i = 0; i < length; i++) {
            j = i;

            while (j > 0 && arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }

    public static void heapsort(int a[], int length) {
        buildheap(a, length);
        int heapsize, i, temp;
        heapsize = length - 1;
        for (i = heapsize; i >= 0; i--) {
            temp = a[0];
            a[0] = a[heapsize];
            a[heapsize] = temp;
            heapsize--;
            satisfyheap(a, 0, heapsize);
        }

    }

    public static void buildheap(int a[], int length) {
        int i, heapsize;
        heapsize = length - 1;

        for (i = (length / 2); i >= 0; i--) {
            satisfyheap(a, i, heapsize);
        }
    }

    public static void satisfyheap(int a[], int i, int heapsize) {
        int l, r, largest, temp;
        l = 2 * i;
        r = 2 * i + 1;
        if (l <= heapsize && a[l] > a[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if (r <= heapsize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            satisfyheap(a, largest, heapsize);
        }
    }

    public static void measure_insertionsort(int a[], int n) {

        long startTime = System.currentTimeMillis();

        long total = 0;
        for (int i = 0; i < 10000000; i++) {
            total += i;
        }
        insertionsort(a, n);
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println();
        System.out.println("insertion sort:  " + elapsedTime);
    }

    public static void measure_quicksort(int a[], int n) {
       

        long startTime = System.currentTimeMillis();

        long total = 0;
        for (int i = 0; i < 10000000; i++) {
            total += i;
        }
        quicksort(a, 1, n-1);
         System.out.println("inja oomad");
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println();
        System.out.println("quick sort:  " + elapsedTime);
    }

    public static void measure_heapsort(int a[], int n) {

        long startTime = System.currentTimeMillis();

        long total = 0;
        for (int i = 0; i < 10000000; i++) {
            total += i;
        }
        heapsort(a, n);
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println();
        System.out.println("heap sort:  " + elapsedTime);
    }

    public static void main(String[] args) {
        int n;
        Random rand=new Random();
        n=2000;
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            
            a[i] = rand.nextInt(100);
          //  System.out.println("a[i]" + a[i]);
        }
  
        measure_insertionsort(a,n);
        measure_heapsort(a, n);
        measure_quicksort(a, n);
    }

}
