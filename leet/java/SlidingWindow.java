//Java 22
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class SlidingWindow {
    public static void main(String[] args) {
        // Generate a stream of integers from 1 to 8
        Stream<Integer> numberStream = IntStream.rangeClosed(1, 8).boxed();

        // Convert the stream to a list of lists representing fixed-size windows
        List<List<Integer>> windows = gatherWindows(numberStream, 3);

        // Print each window
        for (var g : windows) {
            System.out.println(g);
        }
    }

    public static List<List<Integer>> gatherWindows(Stream<Integer> stream, int windowSize) {
        List<Integer> list = stream.collect(Collectors.toList());
        List<List<Integer>> windows = new ArrayList<>();

        for (int i = 0; i < list.size(); i += windowSize) {
            windows.add(list.subList(i, Math.min(i + windowSize, list.size())));
        }

        return windows;
    }
}