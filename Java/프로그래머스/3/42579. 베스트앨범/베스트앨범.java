import java.util.*;

class Solution {
    class Song {
        int id;
        int plays;
        
        Song(int id, int plays) {
            this.id = id;
            this.plays = plays;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        
        // 장르별 재생수 저장
        Map<String, Integer> genreTotal = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            genreTotal.put(genres[i], genreTotal.getOrDefault(genres[i], 0) + plays[i]);
        }
        
        // 장르별로 속한 노래들
        Map<String, List<Song>> genreSongs = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            genreSongs.putIfAbsent(genres[i], new ArrayList<>());
            genreSongs.get(genres[i]).add(new Song(i, plays[i]));
        }
        
        // 장르 키를 리스트해서 정렬
        List<String> sortedGenres = new ArrayList<>(genreTotal.keySet());
        // 정렬식에는 저렇게 외부거 가져와서 해도 됨.(value째로 같이 저장할 필요 없음.)
        sortedGenres.sort((a, b) -> genreTotal.get(b) - genreTotal.get(a));
        
        // 결과 리스트
        List<Integer> result = new ArrayList<>();
        
        // 각 장르별로 최대 2개 노래 선택
        for (String genre : sortedGenres) {
            List<Song> songs = genreSongs.get(genre);
            songs.sort((a, b) -> b.plays - a.plays);
            
            result.add(songs.get(0).id);
            if (songs.size() > 1) {
                result.add(songs.get(1).id);
            }
        }
        
        answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}