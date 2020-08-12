from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework import status
from rest_framework.response import Response
from .serializers import SongSerializer
from .models import Songs

class SongsView(APIView):
    def get(self,request,format=None):
        songs1 = Songs.objects.all()
        serializer1=SongSerializer(songs1,many=True)
        return Response(serializer1.data)

    def post(self,request,format=None):
        serializer = SongSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
# Create your views here.
