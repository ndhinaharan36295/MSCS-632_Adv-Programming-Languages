(* Calculate the mean of the array/list of integers *)
let calculate_mean lst =
  (* Sum all elements in the list after converting them to floats *)
  let sum = List.fold_left ( +. ) 0.0 (List.map float_of_int lst) in

  (* Divide the sum by the number of elements in the list *)
  sum /. (float_of_int (List.length lst))

(* Calculate the median of the array/list of integers *)
let calculate_median lst =
  (* Handle empty list case *)
  if lst = [] then
    nan (* Return NaN for an empty list *)
  else
    (* Sort the list in ascending order *)
    let sorted = List.sort compare lst in
    let len = List.length sorted in

    if len mod 2 = 0 then
      (* If length of array/list is even, take the average of the two middle elements *)
      let mid1 = List.nth sorted (len / 2 - 1) in
      let mid2 = List.nth sorted (len / 2) in
      (float_of_int (mid1 + mid2)) /. 2.0
    else
      (* If the length is odd, return the middle element *)
      float_of_int (List.nth sorted (len / 2))

(* Helper function to count the frequency of each element in a list *)
let count_frequency lst =
  List.fold_left (fun acc x ->
    let count = try List.assoc x acc with Not_found -> 0 in
    (x, count + 1) :: List.remove_assoc x acc
  ) [] lst

(* Calculate the mode(s) of the array/list of integers *)
let calculate_mode lst =
  let freq_list = count_frequency lst in
  let max_count = List.fold_left (fun acc (_, count) -> max acc count) 0 freq_list in
  List.fold_left (fun acc (num, count) ->
    if count = max_count then num :: acc else acc
  ) [] freq_list

(* Main function with an example *)
let () =
  let data = [10; 13; 22; 34; 22; 35; 13; 13] in

  Printf.printf "Data: ";
  List.iter (fun x -> Printf.printf "%d " x) data;
  Printf.printf "\n\n";

  Printf.printf "Mean: %.2f\n" (calculate_mean data);
  Printf.printf "Median: %.2f\n" (calculate_median data);

  let modes = calculate_mode data in
  match modes with
  | [] -> Printf.printf "Mode: No mode (all unique)\n"
  | _ ->
      Printf.printf "Mode: ";
      List.iter (fun x -> Printf.printf "%d " x) modes;
      Printf.printf "\n"