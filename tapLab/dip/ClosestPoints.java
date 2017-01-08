import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class ClosestPoints {

  public static void main(String[] args) throws IOException {
      Scanner scanner = new Scanner(new FileInputStream("points.txt"));
      int n = scanner.nextInt();
      ArrayList<Point> points = new ArrayList<Point>();

      for(int i = 0; i < n; ++i) {
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        points.add(new Point(x, y));
      }

      Collections.sort(points, new Comparator<Point>() {
        @Override
        public int compare(Point a, Point b) {
            if (a.getX() == b.getX()) {
                if (a.getY() < b.getY())
                    return -1;
                if (a.getY() == b.getY())
                    return 0;
                return 1;
            } else {
                if (a.getX() < b.getX())
                    return -1;
                return 1;
            }
        }
      });

      Double result = Math.sqrt(solve(points, 0, n - 1));
      System.out.println(result);
  }

    private static Double solve(ArrayList<Point> points, int left, int right) {
        if (left == right)
            return Double.MAX_VALUE;
        int mid = (left + right) / 2;
        Double d1 = solve(points, left, mid);
        Double d2 = solve(points, mid + 1, right);
        Double minDist = d1;

        if (d2 < minDist)
            minDist = d2;
        Double dist = Math.sqrt(minDist);
        ArrayList<Point> rightPoints = new ArrayList<Point>();
        int xMid = points.get(mid).getX();
        for(int i = mid + 1; i <= right; i++)
            if (Math.abs(points.get(i).getX() - xMid) <= dist)
                rightPoints.add(points.get(i));

        rightPoints.sort(new Comparator<Point>() {
            @Override
            public int compare(Point a, Point b) {
                if (a.getY() < b.getY())
                    return -1;
                if (a.getY() == b.getY())
                    return 0;
                else
                    return 1;
            }
        });

        int current= 0;
        for(int i = left; i <= mid; i++) {
            Point currentPoint = points.get(i);
            while (current< rightPoints.size() && rightPoints.get(current).getY() + dist < currentPoint.getY()) {
              current++;
            }

            for(int j = 0; current+ j < rightPoints.size(); ++j) {
                Point aux = rightPoints.get(current + j);
                Double currentDist = getDistance(currentPoint, aux);

                if (currentDist < minDist)
                    minDist = currentDist;
            }
        }

        return minDist;
    }

    private static double getDistance(Point a, Point b) {
        double xDistance = a.getX() - b.getX();
        double yDistance = a.getY() - b.getY();
        return xDistance * xDistance + yDistance * yDistance;
    }
}
