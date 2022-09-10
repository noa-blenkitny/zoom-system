<h1>Zoom System</h1>
<p>“Zoom” simulation system that has rooms and students that can perform action according to their type. </p>
<p>The implementation focused on use of polymorphism.</p>
<p>There are 3 types of students:</p>
<ul>
<li>Worker student- works when the room he is in gets the command to work.</li>
<li>Lazy student- complains every time that he needs to switch rooms</li>
<li>Responsible student- can send messages to all the students that are in the room with him (as opposed to the other types of students that can only receive messages).</li>
</ul>
<p>There are 3 types of rooms:</p>
<ul>
<li>Standard room- can contain any type of students at creation time.</li>
<li>Lazy room- can contain only lazy students at creation time.</li>
<li>Worker room- can contain only worker students at creation time.</li>
</ul>
<h2>System Functionality</h2>
<p>At initialization the system adds all the students from the input file and assigns them to the lobby.</p>
<p>You can split a room by type or by quantity</p>
<ul>
<li>Splitting by type will create two rooms- lazy room and worker room. The Responsible students from the split room will stay where they are while the lazy and worker student will move to the new rooms according to their types.</li>
<li>Splitting by quantity will create two standard rooms. The first Half of the students from the split room (the students that were added first to the room) will move to the first new room and the other half to the second new room.</li>
</ul>
<p>A room can be split only once.</p>
<p>You can remove a room, removing a room will remove all its sub rooms and move the students in the deleted rooms to the parent room (if the room was created as a result of a split) or to the lobby. </p>
<p>The system has additional functionality such as adding a student, adding a standard room and more.</p>